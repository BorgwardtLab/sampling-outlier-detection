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


A C implementation is available.


Contact
-------

* Author: Mahito Sugiyama
* Affiliation: Machine Learning & Computational Biology Research Group, MPIs Tübingen, Germany
* Mail: mahito.sugiyama@tuebingen.mpg.de