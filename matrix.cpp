#include "matrix.h"

matrix::matrix(int a)
{
    n=a ;
    mat.resize( n , vector<float>( n , 0 ) );
}
void matrix::setmatrix(int l , int c , float val )
{
    mat[l][c]=val ;
}
float matrix::getmatrix(int l , int c)
{
    return mat[l][c] ;
}
void matrix::add()
{
    n++ ;
    for ( int i=0 ; i<n-1 ; i++ )
    {
        cout<<"donner mat["<<i<<"]["<<n-1<<"]" ;
        float val ;
        cin>>val;
        mat[i].push_back(val);
    }
    vector<float> temp ;
    for (int i=0 ; i<n ; i++)
    {

        cout<<"donner mat["<<n-1<<"]["<<i<<"]" ;
        float val ;
        cin>>val;
        temp.push_back(val);
    }
    mat.push_back(temp);
}
ostream& operator<<(ostream& out , matrix m )
{
    for (int i=0 ; i<m.n ; i++)
    {
        for (int j=0 ; j<m.n ; j++ )
        {

            out<<m.mat[i][j]<<" " ;

        }
        out<<endl ;
    }
    return out ;
}

void matrix::algo()
{
    deque <float> temp ;
    vector <float> v ;


   for (int i=1 ; i<n ; i++)
    {
        v.push_back(i) ;
    }

    int u=0;
    int k=0 ;
    temp.push_back(u) ;
    while (!v.empty())
    {
        float minm=5000000 ;
        for (int i=0 ; i<n ; i++)
        {
            if(find(temp.begin(), temp.end(), i)==temp.end())
            {
                if (mat[u][i]<=minm)
                {
                    minm=mat[u][i] ;
                    k=i ;
                }
            }
        }
        temp.push_back(k);
        u=k ;
        v.erase(remove(v.begin(), v.end(), u), v.end());

    }
     cout<<getdistance(temp)<<"\n";
//temp.push_back(0) ;
    temp=opt(temp) ;
        cout<<getdistance(temp)<<"\n";
        while (!  temp.empty())
    {
        cout<<  temp.front()<<"->" ;
          temp.pop_front() ;
    }
//cout<<"\n" ;
}
float matrix::getdistance(deque<float> tempp )
{
    float d=0 ;
    deque<float> temp=tempp ;
    int i = temp.front();
    int w=i ;
    temp.pop_front() ;
    while (! temp.empty())
    {   d= mat[i][temp.front()] + d ;
        i=temp.front();
        temp.pop_front() ;
    }

return d + mat[i][w];
}
deque<float> matrix::two_swap(int i , int j , deque<float> temp)
{
deque<float> tour ;

if (i==n-1 )
{
       tour=temp ;
    int x=tour[n-1] ;
        tour[n-1]=tour[0] ;
        tour[0]=x ;

}
else
{
for (int c=0 ; c<=i-1 ; c++)
{
    tour.push_back(temp[c]) ;
}

int dec =0;
for (int c=i ; c<=j ; c++)
{
    tour.push_back(temp[j-dec]) ;
    dec++ ;
}
for (int c=j+1 ; c<n ; c++)
{
    tour.push_back(temp[c]) ;
}
}
return(tour);
}



deque<float> matrix::opt(deque<float> temp )
{
    float best_distance = getdistance(temp) ;
   deque<float> best_tour  ;
    best_tour=temp ;

int improve=0 ;
  while (improve < 20)
{


for ( int i=0 ; i<n  ; i++)
{ bool test=false ;
    if (i==n-1)
    {
        test=true ;
    }
    for ( int j=0 ; j<n+1  ; j++ )
    {
        if (test==false && j==n)
           {
               break ;
           }

       if(i!=j && i!=j+1 && j!=i+1)
       {temp=two_swap(i,j,temp) ;
         if (getdistance(temp)<best_distance)
            {
                best_tour=temp ;
                best_distance=getdistance(temp);
                improve=0 ;
                //cout<<getdistance(best_tour)<<"\n" ;
            }}

        }
    }
improve++ ;
}

return(best_tour) ;
}

float matrix::suiv(float i)
{
    if (i==n-1)
    {
        return 0 ;
    }
 else
 {
     return i+1 ;
 }

}
void matrix::start(points d)
{
    deque<point>temp=d.getdp() ;
    deque<point>::iterator it ;
    while(!temp.empty())
    {
        for (it= temp.begin()  ; it<temp.end(); it++ )
        {
            setmatrix (temp.front().getindex(),it->getindex(),temp.front().distance(*it)) ;
            setmatrix (it->getindex(),temp.front().getindex(),temp.front().distance(*it)) ;

        }

        temp.pop_front() ;
    }

    algo() ;
}
