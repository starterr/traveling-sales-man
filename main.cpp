#include <iostream>
#include "matrix.h"
#include "point.h"
#include "points.h"
using namespace std;

int main()
{
    points pts;
    point p ;

    int index ;
    float x ;
    float y ;
    matrix m(4) ;
    for (int i=0 ; i<4; i++)
    {
    cout<<"donner p " <<i<<endl ;
  
    cout<<"donner x" <<endl;
    cin>>x ;
   cout<<"donner y " <<endl;
    cin>>y ;
    p.setpoint(x,y,i) ;
    pts.addpoint(p);
    }

    m.start(pts);
    
    return 0;
}
