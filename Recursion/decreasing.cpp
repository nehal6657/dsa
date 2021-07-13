#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void decreasing(int n, int k){
    if(k<n){
        decreasing(n,k+1);
        cout<<k<<" ";
    }

}
void fun(int n){
    if(!n){return;}
    cout<<n<<" ";
    fun(n-1);

}
void fun1(int n){
    if(!n){return;}
    cout<<n<<" ";
    fun1(n-1);
    cout<<n<<" ";
    // fun(n-1);

}

int fact(int n){
    if(n==1) return 1;
    return fact(n-1)*n;

}
int powlinear(int n, int x){
    if(x==0) return 1;
    return powlinear(n,x-1) * n;
}/*
int pow1(int n, int x){
    if(x==0) return 1;
    else if(x%2==0) return pow(pow1(n,x/2),2);
    else if(x%2==1) return n*pow(pow1(n,x/2),2);

}

void arry(vector<int> &v,int i){
    if(i==v.size()) return;
    cout<<v[i]<<" ";
    arry(v,i+1);

}*/
int maxxarr(vector<int> &v,int i){
    if(i==v.size()-1) return v[i];
    else {
        int x = maxxarr(v,i+1);
        return max(v[i],x);
    }
}

int main(){
    //decreasing(10,0);
    

    vector<int> v{1,2,101,300,4,5,6};
    cout<<maxxarr(v,0)<<endl;



}