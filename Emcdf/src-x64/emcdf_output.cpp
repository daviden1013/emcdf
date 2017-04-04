
#include <Rcpp.h>
#include <R.h>
#include <vector>
#include "biEmcdf.h"

using namespace Rcpp;


// [[Rcpp::export]]
NumericMatrix biemcdf_output(NumericVector& x, NumericVector& y, bool is_tie){

  biEmcdf emcdf(x,y, is_tie);
  return(emcdf.getTable());

}
