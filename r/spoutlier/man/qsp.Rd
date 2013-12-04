\name{qsp}
\alias{qsp}
\title{
  Computation of distance-based outlierness scores via sampling
}
\description{
  This function rapidly computes the outlierness score for every data point.
}
\usage{
qsp(X, sample.size = 20, normalize = TRUE, seed)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{X}{
    a data matrix, where rows and columns correspond to data points and
    dimensions, respectively.
  }
  \item{sample.size}{
    number of samples randomly taken from \code{X}
  }
  \item{normalize}{
    a logical value; if this is \code{TRUE}, a data matrix \code{X} is normalized by the
    function \code{normalize}
  }
  \item{seed}{
    a seed used in random sampling (can be skipped)
  }
}
\details{
  \code{qsp} is an efficient outlier-detection method using random sampling.
  It randomly picks up \code{sample.size} data points as a sample set
  and measures the outlierness of each data point in \code{X} by the distance between it
  to the nearest neighbor in the sample set.
  The detection ability of \code{qsp} is robust to changes in sample
  sizes; \code{sample.size} = 20 (default value) is empirically shown to be the best size.
}
\value{
  a vector of outlierness scores of given data points
}
\references{
  Sugiyama, M., Borgwardt, K. M.: Rapid Distance-Based Outlier Detection via Sampling, NIPS 2013.
}
\author{
  Mahito Sugiyama
}
\note{
  A data matrix \code{X} is normalized internally by default.
}
\seealso{
  \code{\link{normalize}}, \code{\link{synth}}
}
\examples{
n <- 1000; d <- 50; n.o <- 10
X <- synth(n, d, n.o) # generate a synthetic dataset with 10 outliers
scores <- qsp(X$data) # compute outlierness scores by SOF
ranks <- order(order(scores, decreasing=TRUE)) # ranks of outlierness
col.vec <- rep(1, n); col.vec[X$index] <- 2
plot(scores, col=col.vec) # plot scores, where outliers are red dots
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ outlier detection }
\keyword{ sampling }% __ONLY ONE__ keyword per line
