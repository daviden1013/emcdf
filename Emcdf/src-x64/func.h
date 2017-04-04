#pragma once
#include <Rcpp.h>
#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;

void func(myMatrix* data, const vector<double>& a, int* p){
  int n = data->nrow();
  int k = data->ncol();

  int sum = 0;
  bool flag = true;
  for(int i=0; i<n; ++i){
    flag = true;
     for(int j=0; j<k; ++j){
      if(data->at(i,j) > a[j]){
        flag = false;
        break;
      }
    }
    if(flag)
      ++sum;
  }

  p[0] = sum;


}
/*
void func1(Rcpp::NumericMatrix* data, Rcpp::NumericVector a, int* p){
  int n = data->nrow();
  NumericMatrix::Column x1 = (*data)(_,0);
  int sum = 0;
  for(int i=0; i<n; ++i)
    if(x1[i] <= a[0])
      ++sum;

  p[0] = sum;
}


void func2(Rcpp::NumericMatrix* data, Rcpp::NumericVector a, int* p){
  int n = data->nrow();
  NumericMatrix::Column x1 = (*data)(_,0);
  NumericMatrix::Column x2 = (*data)(_,1);

  int sum = 0;
  for(int i=0; i<n; ++i)
    if(x1[i] <= a[0] && x2[i] <= a[1])
      ++sum;

  p[0] = sum;
}


void func3(Rcpp::NumericMatrix* data, Rcpp::NumericVector a, int* p){
  int n = data->nrow();
  NumericMatrix::Column x1 = (*data)(_,0);
  NumericMatrix::Column x2 = (*data)(_,1);
  NumericMatrix::Column x3 = (*data)(_,2);
  int sum = 0;
  for(int i=0; i<n; ++i)
    if(x1[i] <= a[0] && x2[i] <= a[1] && x3[i] <= a[2])
      ++sum;

  p[0] = sum;
}

void func4(Rcpp::NumericMatrix* data, Rcpp::NumericVector a, int* p){
  int n = data->nrow();
  NumericMatrix::Column x1 = (*data)(_,0);
  NumericMatrix::Column x2 = (*data)(_,1);
  NumericMatrix::Column x3 = (*data)(_,2);
  NumericMatrix::Column x4 = (*data)(_,3);
  int sum = 0;
  for(int i=0; i<n; ++i)
    if(x1[i] <= a[0] && x2[i] <= a[1] && x3[i] <= a[2] && x4[i] <= a[3])
      ++sum;

  p[0] = sum;
}

void func5(Rcpp::NumericMatrix* data, Rcpp::NumericVector a, int* p){
  int n = data->nrow();
  NumericMatrix::Column x1 = (*data)(_,0);
  NumericMatrix::Column x2 = (*data)(_,1);
  NumericMatrix::Column x3 = (*data)(_,2);
  NumericMatrix::Column x4 = (*data)(_,3);
  NumericMatrix::Column x5 = (*data)(_,4);
  int sum = 0;
  for(int i=0; i<n; ++i)
    if(x1[i] <= a[0] && x2[i] <= a[1] && x3[i] <= a[2] && x4[i] <= a[3] && x5[i] <= a[4])
      ++sum;

  p[0] = sum;
}
*/
