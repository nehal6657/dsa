#include<iostream>
using namespace std;

int add(int n, int m){
    static int s =0;
    if(n>0){
        return add(n-1,m) * m;

    }
    else{
        return 1;
    }
    
    
}
int main(){
    int x;

    x = add(5,2);
    cout<<x;
    return 0;
}