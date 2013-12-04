\name{normalize}
\alias{normalize}
\title{
  Normalization
}
\description{
  This function normalizes a given dataset.
}
\usage{
normalize(X)
}
\arguments{
  \item{X}{
    a data matrix, where rows and columns correspond to data points and
    dimensions, respectively.
  }
}
\details{
  \code{normalize} performs normalization by dividing feature values by
  their standard deviation in each dimension.
  This process is especially important for distance- or proximity-based
  methods to ensure that each dimension has an equal level of importance
  [Aggarwal; 2013, Chapter 12.10].
}
\value{
  a normalized data matrix
}
\references{
  Aggarwal, C. C.: Outlier Analysis, Springer, 2013.

  Sugiyama, M., Borgwardt, K. M.: Rapid Distance-Based Outlier
  Detection via Sampling, NIPS 2013.
}
\author{
  Mahito Sugiyama
}
\examples{
X <- matrix(rnorm(100 * 2, 10, 1), ncol=2)
X <- normalize(X)
}
