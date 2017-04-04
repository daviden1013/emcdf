#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int single(NumericMatrix& data, const NumericVector& a){
  int n = data.nrow();
  int k = data.ncol();

  std::vector<NumericMatrix::Column> x;
  for(int i=0; i<k; ++i){
    NumericMatrix::Column temp = data(_,i);
    x.push_back(temp);
  }

  int sum = 0;
  bool flag = true;
  for(int i=0; i<n; ++i){
    flag = true;
     for(int j=0; j<k; ++j){
      if(x[j][i] > a[j]){
        flag = false;
        break;
      }
    }
    if(flag)
      ++sum;
  }

  return sum;

}

// [[Rcpp::export]]
int single1(const NumericMatrix& data, const NumericVector& a){
  int n = data.nrow();
  const NumericMatrix::ConstColumn x1 = data(_,0);
  int sum = 0;
  for(int i=0; i<n; ++i)
    if(x1[i] <= a[0])
      ++sum;

  return sum;
}


// [[Rcpp::export]]
int single2(const NumericMatrix& data, const NumericVector& a){
  int n = data.nrow();
  const NumericMatrix::ConstColumn x1 = data(_,0);
  const NumericMatrix::ConstColumn x2 = data(_,1);
  int sum = 0;
  for(int i=0; i<n; ++i)
    if(x1[i] <= a[0] && x2[i] <= a[1])
      ++sum;

  return sum;
}

// [[Rcpp::export]]
int single3(const NumericMatrix& data, const NumericVector& a){
  int n = data.nrow();
  const NumericMatrix::ConstColumn x1 = data(_,0);
  const NumericMatrix::ConstColumn x2 = data(_,1);
  const NumericMatrix::ConstColumn x3 = data(_,2);
  int sum = 0;
  for(int i=0; i<n; ++i)
    if(x1[i] <= a[0] && x2[i] <= a[1] && x3[i] <= a[2])
      ++sum;

  return sum;
}

// [[Rcpp::export]]
int single4(const NumericMatrix& data, const NumericVector& a){
  int n = data.nrow();
  const NumericMatrix::ConstColumn x1 = data(_,0);
  const NumericMatrix::ConstColumn x2 = data(_,1);
  const NumericMatrix::ConstColumn x3 = data(_,2);
  const NumericMatrix::ConstColumn x4 = data(_,3);
  int sum = 0;
  for(int i=0; i<n; ++i)
    if(x1[i] <= a[0] && x2[i] <= a[1] && x3[i] <= a[2] && x4[i] <= a[3])
      ++sum;

  return sum;
}

// [[Rcpp::export]]
int single5(const NumericMatrix& data, const NumericVector& a){
  int n = data.nrow();
  const NumericMatrix::ConstColumn x1 = data(_,0);
  const NumericMatrix::ConstColumn x2 = data(_,1);
  const NumericMatrix::ConstColumn x3 = data(_,2);
  const NumericMatrix::ConstColumn x4 = data(_,3);
  const NumericMatrix::ConstColumn x5 = data(_,4);
  int sum = 0;
  for(int i=0; i<n; ++i)
    if(x1[i] <= a[0] && x2[i] <= a[1] && x3[i] <= a[2] && x4[i] <= a[3] && x5[i] <= a[4])
      ++sum;

  return sum;
}

