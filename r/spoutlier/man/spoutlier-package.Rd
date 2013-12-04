\name{spoutlier-package}
\alias{spoutlier-package}
\alias{spoutlier}
\docType{package}
\title{
  Rapid outlier detection via sampling
}
\description{
  Detecting distance-based outliers using random sampling in an
  efficient manner
}
\details{
\tabular{ll}{
Package: \tab spoutlier\cr
Type: \tab Package\cr
Version: \tab 1.0\cr
Date: \tab 2013-12-03\cr
License: \tab GPL (>= 2)\cr
}
This package containts a function \code{qsp} for efficient outlier detection with
additional functions.
}
\author{
Mahito Sugiyama

Maintainer: Mahito Sugiyama \code{<mahito.sugiyama@tuebingen.mpg.de>}
}
\references{
  Sugiyama, M., Borgwardt, K. M.: Rapid Distance-Based Outlier
  Detection via Sampling, NIPS 2013.
}
\keyword{ outlier detection }
\keyword{ sampling }
\examples{
n <- 1000; d <- 50; n.o <- 10
X <- synth(n, d, n.o)
  # Generate a dataset with n (= 1000) objects and d (= 50) dimensions,
  # where the first n.o (= 10) objects are outliers
score <- qsp(X$data, 20)
  # compute outlierness scores by SOF with the given sample size 20
ranking <- order(order(score, decreasing=TRUE))
  # for example, compute ranks of scores
col.vec <- rep(1, n); col.vec[X$index] <- 2
plot(score, col=col.vec)
  # plot scores, where red dots are outliers
}
