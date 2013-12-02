Rapid outlier detection via sampling
=========================================================

Rapid computation of distance-based outlierness scores via sampling


Summary
-------

An efficient algorithm for outlier detection, which performs sampling once and measures outlierness of each data point by the distance from it to the nearest neighbor in the sample set.
This algorithm has the following advantages:

* **Scalable**; the time complexity is linear in the number of data points,
* **Effective**; it is empirically shown to be the most effective on average among existing distance-based outlier detection methods, and
* **Easy to use**; you only need to input the number of samples, and small sample size (default value is 20) is shown to be a good choice.

Please see the following paper for detailed information and refer it in your published research:

* Sugiyama, M., Borgwardt, K. M.: **Rapid Distance-Based Outlier Detection via Sampling**,
  *Advances in Neural Information Processing Systems (NIPS 2013)*, 2013.
  [PDF](http://media.nips.cc/nipsbooks/nipspapers/paper_files/nips26/296.pdf) [Supplemental](http://media.nips.cc/nipsbooks/nipspapers/paper_files/nips26/296.zip)


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


Information
-----------

* Author: Mahito Sugiyama
* Affiliation: Machine Learning & Computational Biology Research Group, MPIs Tübingen, Germany
* Mail: mahito.sugiyama@tuebingen.mpg.de