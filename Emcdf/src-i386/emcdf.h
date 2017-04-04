#pragma once
#include <Rcpp.h>
#include <thread>
#include <vector>
#include "Matrix.h"

using namespace Rcpp;

myMatrix* copy(Rcpp::NumericMatrix& x, int row, int nrow);

class emcdf{
public:
  explicit emcdf(Rcpp::NumericMatrix& x, int n);
  ~emcdf();
  void cdf(Rcpp::NumericVector& a);
  int getResult();

private:
  int num;
  int k;
  std::thread* t;
  std::vector<myMatrix*> data;
  int size;
  int* result;

};


