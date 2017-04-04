#' @importFrom Rcpp evalCpp
#' @useDynLib Emcdf
#' @title Initialize threads and split data
#' @description This function initializes threads and splits data. Retures an S4 object of class "emcdf_obj" that is ready for parallel computation.
#' @param data a numeric matrix stores data. Colunms as variables.
#' @param num an integer specifies number of threads to initialize.
#'
#' @author En-shuo Hsu
#' @details
#' The input data must be a numeric matrix with variables as columns. The choice of "num" is machine dependent.
#' A reasonable number would be the total number of CPU cores - 1. Call coreNum() to get CPU core number.
#' @export
#' @import methods
#'
#' @examples
#' n = 10^5
#' set.seed(123)
#' x = rnorm(n)
#' y = rnorm(n)
#' z = rnorm(n)
#' data = cbind(x, y, z)
#'
#' #decide thread number
#' num = coreNum() - 1
#'
#' #initialize threads
#' obj = initF(data, num)
#'
#' #compute empirical CDF
#' emcdf(obj, c(0.5, 0.5, 0.5))
#'
#' @return
#' an S4 object of class "emcdf_obj", holding pointer to an C++ object. When passed to function emcdf(),
#' it computes joint CDF with multi-threads.
#'

initF = function(data, num = 2){
  if(!is.numeric(data) || !is.matrix(data))
    stop('data must be a numeric matrix.')
  if(num%%1!=0 || length(num) != 1)
    stop("num must be a integer with length 1.")
  if(nrow(data) < num)
    stop("input size must be greater than thread number.")

  return (new("emcdf_obj", p = build(data, num), k = ncol(data), n = nrow(data)))
}

