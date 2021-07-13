#include<iostream>
using namespace std;

int i =0;
void toh(int n, int a,int b, int c){
    if(n==0) return;
    i++;
    toh(n-1,a,c,b);
    cout<<n<<" "<<a<<" -> "<<b<<"\n";
    toh(n-1,c,b,a);

}

int main(){
    toh(4,10,11,12);
    cout<<i;

    return 0;
}