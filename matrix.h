#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include<deque>
#include <iostream>
#include <algorithm>
#include "points.h"
using namespace std;
class matrix
{
    vector<vector<float> > mat ;
    int n ;
    public:
    matrix(int);
    void setmatrix (int , int , float) ;

    float getmatrix(int , int ) ;
    float getdistance(deque<float>) ;
    friend ostream& operator<<(ostream& , matrix ) ;
    void add () ;
    float suiv(float ) ;
   deque<float> opt(deque<float> ) ;
    deque<float> two_swap(int , int , deque<float> ) ;
    void algo() ;
    void start(points) ;
};

#endif // MATRIX_H
