\name{synth}
\alias{synth}
\title{
  Synthetic data generation
}
\description{
  This function generates a synthetic dataset including outliers.
}
\usage{
synth(n = 1000, d = 50, n.o = 10, n.cl = 5, m.sd = 1, s.sd = 1, seed)
}
\arguments{
  \item{n}{
    number of objects
  }
  \item{d}{
    number of dimensions
  }
  \item{n.o}{
    number of outliers
  }
  \item{n.cl}{
    number of clusters
  }
  \item{m.sd}{
    SD of means for clusters
  }
  \item{s.sd}{
    SD of SDs for clusters
  }
  \item{seed}{
    seed for random generation
  }
}
\details{
  \code{synth} first generates inliers (non-outliers) by a Gaussian
  mixture model with \code{n.cl} equally weighted processes, resulting
  in \code{n.cl} clusters. The mean and the SD of each cluster are
  randomly set from Gaussian distributions N(0, \code{m.sd}) and N(0,
  \code{s.sd}), respectively. Then, \code{n.o} outliers are generated from
  a uniform distribution in the range from the minimum to the maximum of inliers.

  This dataset is first used by Kriegel et al. [KDD 2008] and also used
  by Pham and Pagh [KDD 2012] and Sugiyama and Borgwardt [NIPS 2013].
}
\value{
  \item{data }{a data matrix with \code{n} rows (data points) and
  \code{d} columns (dimensions)}
  \item{index }{indexes of outliers}
}
\references{
  Kriegel, H.-P., Schubert, M., Zimek, A.: Angle-based outlier detection
  in high-dimensional data, KDD 2008.

  Pham, N., Pagh, R.: A near-linear time approximation algorithm for
  angle-based outlier detection in high-dimensional data, KDD 2012.

  Sugiyama, M., Borgwardt, K. M.: Rapid Distance-Based Outlier
  Detection via Sampling, NIPS 2013.
}
\author{
  Mahito Sugiyama
}
\examples{
X <- synth(1000, 50, 10)
}
