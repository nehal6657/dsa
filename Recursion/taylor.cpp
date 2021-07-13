#include<iostream>
using namespace std;

double taylor(int n, int x){
    static double p = 1,f = 1;
    double r;
 

   if(n==0){
       return 1;
   }
   else{
       r = taylor(n-1,x);
       p = p*x;
       f = f*n;
       return r + p/f; 
   }

}
// horners' rule
double e(int n,int x){
    static double s =1 ;
    if(n==0)
        return s;    
    s = 1 + x*s/n ;
    return e(n-1,x);

}



int main(){
    int x=3;
    double x1 = taylor(10,x);
    double x2 = e(10,x);
    cout<<x1<<" "<<x2;
    return 0;
}