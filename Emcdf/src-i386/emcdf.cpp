#include <Rcpp.h>
#include <thread>
#include <vector>
#include "Matrix.h"
#include "emcdf.h"
#include "func.h"

using namespace Rcpp;


myMatrix* copy(Rcpp::NumericMatrix& x, int row, int nrow){

  myMatrix* out = new myMatrix(nrow, x.ncol());
  int firstRow = 0;
  while(firstRow < nrow){
    for(int j=0; j<x.ncol(); ++j){
      out->at(firstRow,j) = x.at(firstRow + row,j);
    }
    ++firstRow;
  }
  return out;
}

  emcdf::emcdf(Rcpp::NumericMatrix& x, int n){
    //initialize members
    t = new std::thread[n];
    num = n;
    k = x.ncol();
    size = x.nrow()/num;
    result = new int[num];

    int i = 0;
    for(; i<num - 1; ++i)
      data.push_back(copy(x, i*size, size));

    data.push_back(copy(x, i*size, x.nrow() - i*size));
  }

  emcdf::~emcdf(){
    delete[] t;
    for(int i=0; i<num; ++i)
      delete data[i];
    delete[] result;
  }

  void emcdf::cdf(NumericVector& a){
    std::vector<double> va(a.size());
    for(int i=0; i<a.size(); ++i)
      va[i] = a[i];

    for(int i=0; i<num; ++i){
      t[i] = std::thread(func, data[i], va, result + i);
    }
    for(int i=0; i<num; ++i)
      t[i].join();
  }

  int emcdf::getResult(){
    int sum = 0;
    for(int i=0; i<num; ++i)
      sum += result[i];
    return sum;
  }

//[[Rcpp::export]]
RcppExport SEXP build(SEXP x_in, int num){
  NumericMatrix x(x_in);
  emcdf* em = new emcdf(x, num);
  XPtr<emcdf> p(em, true);
  return p;
}

//[[Rcpp::export]]
SEXP compute(SEXP& p_in, NumericVector& a){
  XPtr<emcdf> p(p_in);
  p->cdf(a);
  return wrap(p->getResult());
}




