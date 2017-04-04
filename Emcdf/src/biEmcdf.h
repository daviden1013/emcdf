#pragma once
#include <vector>
#include <Rcpp.h>
#include <R.h>

using namespace Rcpp;

class biEmcdf {
public:
	biEmcdf(NumericVector& x, NumericVector& y, bool is_tie);
	~biEmcdf();
	int n;
	bool tie;
	double** table_;
	NumericMatrix* out;
  std::vector<int>* uniqueX;
  std::vector<int>* uniqueY;
  NumericMatrix& getTable();
};

