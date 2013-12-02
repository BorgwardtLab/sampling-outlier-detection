// copyright: see the header of "qsp.c"
#include "stdlib2.h"
#include "readCSV.h"
#include "qsp.h"
#include "iqsort.h"

// Measure running time
double measureTime() {
  struct rusage t;
  struct timeval tv;
  getrusage(RUSAGE_SELF, &t);
  tv = t.ru_utime;
  return tv.tv_sec + (double)tv.tv_usec * 1e-6;
}

// MAIN function
int main(int argc, char *argv[]) {
  char *input, *output = "output";
  int k = 10, norm = 1, srt = 1, opt;
  long i, j, n = 0, d = 0, seed = 0, n_sample = 20, *index = NULL;
  double t1, t2, t3, t4; // for time measurement
  double *X = NULL, *score = NULL;
  FILE *fp;

  if (argc == 1) {
    printf("Please use the -h option to get usage information.\n");
    exit(0);
  }

  t1 = measureTime();

  while ((opt = getopt(argc, argv, "vhi:o:s:r:nqk:")) != -1) {
    switch (opt) {
    case 'v':
      printf("qsp version 1.0\n");
      exit(0);
    case 'h':
      printf("Usage: ./qsp -i <input_file> -o <output_file> -s <samplesize> [options]\n");
      printf("Synopsis: distance-based outlier detection via sampling (qsp)\n");
      printf("Options:\n");
      printf("  -i: input file name\n");
      printf("  -o: output file name (default value: output)\n");
      printf("  -s: sample size      (default value: 20)\n");
      printf("  -r: seed for sampling (can be skipped, randomly set in "
             "default)\n");
      printf("  -n: do not perform normalization\n");
      printf("  -q: do not perform quick sort of resulting scores (do not "
             "produce ranking)\n");
      printf("  -k: number of top-ranked outliers to be reported to stdout (it is "
             "used only the case where \"-q\" is not specified)\n");
      printf("Example: ./qsp -i sample.csv -o output -s 20\n");
      exit(0);
    case 'i':
      input = optarg;
      break;
    case 'o':
      output = optarg;
      break;
    case 's':
      n_sample = atoi(optarg);
      break;
    case 'r':
      seed = atoi(optarg);
      break;
    case 'n':
      norm = 0;
      break;
    case 'q':
      srt = 0;
      break;
    case 'k':
      k = atoi(optarg);
      break;
    default:
      fprintf(stderr, "ERROR: an unknown option is set\n");
      exit(1);
    }
  }

  // read the CSV file
  printf("reading file from \"%s\"...", input);
  fflush(stdout);
  readCSVFile(&X, &n, &d, input);
  printf("end\n\n");
  printf("number of data points: %ld\n", n);
  printf("number of dimensions : %ld\n\n", d);
  fflush(stdout);

  if (n_sample > n) {
    fprintf(stderr, "ERROR: sample size should be smaller than the number of objects "
           "(rows)\n");
    exit(1);
  }
  if (k > n) {
    fprintf(stderr, "ERROR: number of top-ranked outliers should be smaller than the number of objects "
           "(rows)\n");
    exit(1);
  }

  t3 = measureTime();

  // normalization
  if (norm == 1) {
    printf("normalizing...");
    fflush(stdout);
    normalize(X, n, d);
    printf("end\n");
    fflush(stdout);
  }

  // compute qsps
  printf("computing qsp scores...");
  fflush(stdout);
  score = (double *)malloc(sizeof(double) * n);
  qsp(X, n, d, n_sample, seed, score);
  printf("end\n");
  fflush(stdout);

  t4 = measureTime();

  // write resulting scores to an output file
  printf("writing scores to the file \"%s\"...", output);
  fflush(stdout);
  fp = fopen(output, "w");
  if (fp == NULL) {
    printf("%s: cannot open the file\n", output);
    exit(1);
  }
  for (i = 0; i < n; i++) {
    fprintf(fp, "%f\n", score[i]);
  }
  fclose(fp);
  printf("end\n");
  fflush(stdout);

  // index qsort for ranking
  if (srt == 1) {
    index = (long *)malloc(sizeof(long) * n);
    for (i = 0; i < n; i++) {
      index[i] = i;
    }
    iqsort(index, score, n);

    printf("\n");
    printf("indexes of top-%d ourliers:\n", k);
    printf("  ");
    for (i = 0; i < (k - 1); i++) {
      printf("%ld, ", index[i] + 1);
    }
    printf("%ld\n", index[i] + 1);
  }

  free(X);
  X = NULL;
  free(score);
  score = NULL;
  free(index);
  index = NULL;

  t2 = measureTime();

  printf("\n");
  printf("Total running time:\n");
  printf("  %f sec.\n", t2 - t1);
  printf("Running time for score computation (without sorting and file "
         "input & output):\n");
  printf("  %f sec.\n", t4 - t3);

  return 0;
}
