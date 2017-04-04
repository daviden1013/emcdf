#include <Rcpp.h>
#include <thread>
using namespace Rcpp;

// [[Rcpp::export]]
unsigned int getCoreNum(){
  return std::thread::hardware_concurrency();
}
