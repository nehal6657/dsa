#include<iostream>
#include<vector>
#include<iostream>
using namespace std;
int fibo(int n, vector<int> &v){
    if(n==0||n==1) return n;
    if(v[n]) return v[n];
    int f1 = fibo(n-1, v);
    int f2 = fibo(n-2, v);
    int f = f1+f2;
    v[n] = f;
    return f;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n+1,0);
    int ans = fibo(n,v);
    cout<<ans;
    return 0;
}