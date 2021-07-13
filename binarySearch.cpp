#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int n, int k, int a[]){
    int u = n-1;
    int l = 0;
    int m=0;
    while(l<=u){
        m = (u+l)/2;
        if(a[m]==k){
            return m+1;
        }
        else if (a[m]<k)
        {
            l = m+1;
        }
        else{
            u = m-1;
        }

    }
    return -1;

}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    int x = binarySearch(n,k,a);
    cout<<x;
    return 0;
}