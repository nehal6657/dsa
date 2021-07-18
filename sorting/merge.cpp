#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
typedef vector<int> vi;
int c=0;
void merge(vi &a, vi &b, vi &c){
    int i=0, j = 0, k= 0;
    int n = a.size(), n2 = b.size();
    //vector<int> c(n+n2);
    while(i<n && j<n2){
        if(a[i] < b[j]) {
            c[k] = a[i];
            k++;
            i++;
        }
        else {
            c[k] = b[j];
            k++;
            j++;            
        }
        
    }
    for(i;i<n;i++,k++){
        c[k] = a[i];
    }
    for(j;j<n2;j++,k++){
        c[k] = b[j];
    }
}

void sort(vector<int> &a){
    int n = a.size();
    if(n<=1) return;
    vi x, y;
    for(int i=0;i<n;i++){
        if(i<n/2) x.push_back(a[i]);
        else y.push_back(a[i]);
    }
    sort(x);
    sort(y);
    merge(x,y,a);
}


int main(){
    vector<int> v11{5,4,3,2,1,12,15,18,1,22,101,54};
    sort(v11);
    for(int i=0;i<v11.size();i++){
        cout<<v11[i]<<" ";
    }

    return 0;
}