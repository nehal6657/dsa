#include<iostream>
using namespace std;
int * merge(int *a, int *b,int n,int m){
    int *c = new int[n+m];
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            c[k]= a[i];
            i++;
            k++;
        }
        else if(a[i]>=b[j]){
            c[k]=b[j];
            j++;
            k++;
        }
    }
    if(j==m){
        for(i;i<n;i++,k++){
            c[k] =  a[i];
        }
    }
    if(i==n){
        for(j;j<m;j++,k++){
            c[k]=b[j];
        }
    }
    return c;


}

int main(){
    int a[5] = {1,4,7,8,11};
    int b[6] = {1,2,3,7,9,10};
    
    int *c = merge(a, b,5,6);
    for(int i =0;i<11;i++){
        cout<<c[i]<<" ";
    }


    return 0;
}