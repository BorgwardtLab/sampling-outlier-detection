Rapid outlier detection via sampling
=========================================================

Rapid computation of distance-based outlierness scores via sampling


Usage
-----

Given a multivariate dataset, it computes outlierness scores for all data point.
To use it, type:

	$ make   
	$ ./qsp -i <input_file> -o <output_file> -s <samplesize>
	
* `<input_file>` should be a comma-separated text file without row and column names.
Rows and columns correspond to respective data points and dimensions.
* `<samplesize>` is used as the number of samples in sampling.
* Resulting scores are output to the file `<output_file>`.
* In addition, indexes of top-k (can be specified by the option `-k`) outliers and running time are shown at standard output.
* Please use the -h option to get more detailed usage information.


Example
-------

	$ make
	$ ./qsp -i sample.csv -o output -s 20
	  reading file from "sample.csv"...end
	
	  number of data points: 1000
	  number of dimensions : 50
		
	  normalizing...end
	  computing qsp scores...end
	  writing scores to the file "output"...end
	
	  indexes of top-10 ourliers:
	    4, 10, 5, 6, 1, 8, 9, 3, 7, 2
	
	  Total running time:
	    0.014644 sec.
	  Running time for score computation (without sorting and file input & output):
	    0.002222 sec.


Contact
-------

* Author: Mahito Sugiyama
* Affiliation: Machine Learning & Computational Biology Research Group, MPIs Tübingen, Germany
* Mail: mahito.sugiyama@tuebingen.mpg.de