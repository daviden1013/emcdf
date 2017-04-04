
#' @title Computes bivariate empirical joint distribution
#' @description This function computes empirical joint distribution (joint CDF) table with dynamical programming.
#' @param data a numeric matrix stores data.
#'
#' @author En-shuo Hsu
#' @details
#' When data is a numeric matrix, this function computes joint empirical CDF with single thread.
#' When data is an object of class "emcdf_obj", it computes with multi-thread. Parameter "a"
#' must have equal length as the column number of data. Both single-thread and multi-thread emcdf
#' algorithms are faster than using the bulit-in function sum\{base\}. See example for simulation.
#' Note that initializing threads and spliting data takes time though it's a one-time task.
#' Thus for big data, big number of CDF computation, multi-thread is recommended. Yet for small data,
#' small number of CDF computation, single thread is faster.
#' @export
#' @examples
#' n = 10^2
#' set.seed(123)
#' x = rnorm(n)
#' y = rnorm(n)
#' data = cbind(x, y)
#' Biemcdf(data)
#'
#' @return
#' a numeric as value of empirical joint CDF function.
#'
#'
Biemcdf = function(data){
  return (biemcdf_output(data[,1], data[,2], FALSE))
}
