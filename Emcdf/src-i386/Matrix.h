#pragma once
#include <vector>

using namespace std;

class myMatrix{
public:
  explicit myMatrix(int n, int m): numrow(n), numcol(m){
    col = new vector<vector<double>>(numcol);
    for(int i=0; i<numcol; ++i)
      col->at(i) = vector<double>(numrow);
  };
  ~myMatrix(){
    delete col;
  };
  double& at(int x, int y){
    return col->at(y)[x];
  };
  vector<double>& getCol(int i){
    return col->at(i);
  };
  int nrow(){
    return numrow;
  };
  int ncol(){
    return numcol;
  }


private:
  vector<vector<double>>* col;
  int numcol;
  int numrow;
};
