// copyright: see the header of "qsp.c"
#include "stdlib2.h"
#include "readCSV.h"

#define WORD 30

// n: # of rows, d: # of columns
void readCSVFile(double **X, long *n, long *d, char *filename) {
  char w[WORD], *str = NULL, *ep = NULL;
  long countNL = 0;  // # of breaks
  long countSep = 0; // # of commas
  long cols = 0;     // # of columns
  long i, j, k, d_tmp = 0;
  double val;

  // read a file "filename" as text
  str = readTextFile(filename);

  // get the number rows and columns
  for (i = 0; i < strlen(str); i++) {
    switch (str[i]) {
    case ',':
      countSep++;
      cols++;
      break;
    case '\n':
      countNL++;
      cols++;
      d_tmp = (d_tmp > cols) ? d_tmp : cols;
      cols = 0;
      break;
    }
  }
  *n = countNL;
  *d = d_tmp;

  // generate an array for storing a CSV file
  *X = (double *)calloc((*n) * (*d) * sizeof(double), sizeof(double));
  if (*X == NULL) {
    printf("ERROR: cannot allocate memory. \"*X\" is NULL. \n");
    free(str);
    str = NULL;
    exit(1);
  }

  // copy CSV data to an array X
  i = 0;
  j = 0;
  k = 0;
  w[0] = '0';
  w[1] = '\0';
  while (j < (*n) * (*d)) {
    switch (str[i]) {
    case ',':
    case '\n':
      val = strtod(w, &ep);
      if (*ep != '\0')
        printf("WARNING: conversion may be incorrect in (%ld, %ld)\n", j / (*d),
               j % (*d));
      (*X)[j] = val;
      j++;
      if (str[i] == '\n') {
        while (j % (*d) > 0) {
          (*X)[j] = 0.0;
          j++;
        }
      }
      k = 0;
      w[0] = '0';
      w[1] = '\0';
      break;
    default:
      if (k + 1 < sizeof(w)) {
        w[k] = str[i];
        w[k + 1] = '\0';
        k++;
      } else if (k + 1 == sizeof(w)) {
        printf("WARNING: too many digits in (%ld, %ld)\n", j / (*d), j % (*d));
        k++;
      }
      break;
    }
    i++;
  }

  // free memory
  free(str);
  str = NULL;

  return;
}

char *readTextFile(char *filename) {
  long fsize;
  char *str = NULL;
  FILE *fp = NULL;

  // file open
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("ERROR: cannot open the file \"%s\"\n", filename);
    exit(1);
  }

  // get file size
  fseek(fp, 0L, SEEK_END);
  fsize = ftell(fp);

  // memory allocation
  str = (char *)malloc(sizeof(char) * fsize);
  if (str == NULL) {
    printf("ERROR: cannot allocate memory. \"str\" is NULL.\n");
    fclose(fp);
    exit(1);
  }

  // initialize seek position
  fseek(fp, 0L, SEEK_SET);

  // read text
  fread(str, sizeof(char) * fsize, 1, fp);

  // close file connection
  fclose(fp);

  return str;
}
