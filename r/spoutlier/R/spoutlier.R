# outlier detection via sampling
qsp <- function(X, sample.size = 20, normalize = TRUE, seed) {
  if (is.vector(X)) X <- as.matrix(X, ncol=1)
  n <- nrow(X)
  d <- ncol(X)
  if (sample.size > n) sample.size <- n
  if (!missing(seed)) set.seed(seed) # set seed if you want
  if (normalize) X <- normalize(X)
  sample.id <- sample(1:n, sample.size)

  .C("qsp",
     as.double(as.vector(X)),
     as.integer(n),
     as.integer(d),
     as.double(as.vector(X[sample.id,])),
     as.integer(as.vector(sample.id - 1)),
     as.integer(sample.size),
     result = double(n)
     )$result
}

# ------------------------------------ #

# nomalization of data
normalize <- function(X) {
  res <- .C("normalize",
            as.double(as.vector(X)),
            as.integer(nrow(X)),
            as.integer(ncol(X)),
            as.double(as.vector(colMeans(X))),
            result = double(nrow(X) * ncol(X))
            )$result
  return(matrix(res, nrow=nrow(X)))
}

# generate synthetic data
synth <- function(n = 1000, d = 50, n.o = 10, n.cl=5, m.sd = 1, s.sd = 1, seed) {
  n.each <- n / n.cl
  if (n %% n.cl != 0)
      stop("n %% n.cl should be 0")
  size <- n.each * d
  if (!missing(seed))
      set.seed(seed) # set seed if you want

  ml <- matrix(rnorm(n.cl * d, 0, m.sd), ncol=d) # generate means of clusters
  sl <- abs(rnorm(n.cl * d, 0, s.sd)) # generate SDs of clusters

  # generate inlier
  d.list <- vector("list", n.cl)
  for (i in 1:n.cl) {
    d.list[[i]] <- matrix(rnorm(size, 0, sl[i]), ncol=d)
    d.list[[i]] <- t(t(d.list[[i]]) + ml[i,])
  }
  X <- do.call("rbind", d.list)

  # generate outlier
  id.o <- sample.int(n, n.o)
  for (i in 1:d) {
    X[id.o, i] <- runif(n.o, min(X[,i]), max(X[,i]))
  }

  return(list(data=X, index=id.o))
}
