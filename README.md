Rapid outlier detection via sampling
=========================================================

Rapid computation of distance-based outlierness scores via sampling


Summary
-------

This is an efficient algorithm for outlier detection, which performs sampling once and measures the outlierness of each data point by the distance from it to the nearest neighbor in the sample set.
This algorithm has the following advantages:

* **Scalable**; the time complexity is linear in the number of data points,
* **Effective**; it is empirically shown to be the most effective on average among existing distance-based outlier detection methods, and
* **Easy to use**; it requires only one parameter, the number of samples, and small sample size (the default value is 20) is shown to be a good choice.

Please see the following paper for the detailed information about this method and refer it in your published research:

* Sugiyama, M., Borgwardt, K. M.: **Rapid Distance-Based Outlier Detection via Sampling**,
    *Advances in Neural Information Processing Systems (NIPS 2013)*, 467-475, 2013.  [PDF](http://papers.nips.cc/paper/5127-rapid-distance-based-outlier-detection-via-sampling.pdf) [Supplement](http://papers.nips.cc/paper/5127-rapid-distance-based-outlier-detection-via-sampling-supplemental.zip)


Both an R package and C implementation are available.


Contact
-------

* Author: Mahito Sugiyama
* Affiliation: ISIR, Osaka University, Japan
* Mail: mahito@ar.sanken.osaka-u.ac.jp
