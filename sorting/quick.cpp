#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;

int partition(vector<int> &v, int l, int h){
    int pivot= v[l], i =l, j = h;
    do{
        do{i++;} while(v[l]<=pivot);
        do{j--;} while(v[l]>pivot);
        if(i<j) swap(v[i],v[j]);
    }while(i<j);
    swap(v[l], v[j]);
    return j;
}
void Quicksort(vector<int> &v, int l, int h){
    int j;
    if(l<h){
        j = partition(v,l,h);
    }
    Quicksort(v,l,j);
    Quicksort(v,j+1,h);
}
int main(){
    vector<int> v1{4,3,12,312,1,2,4,9,0};
    Quicksort(v1,0,v1.size()-1);
    for(auto x: v1) cout<<x<<" ";
    return 0;
}