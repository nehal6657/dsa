#include<iostream>
using namespace std;
int a[10] = {1,2,3,6,14,21,33,41,50,15};
int bin_search(int l, int h, int k){
    if(l<=h){
        int m = (l+h)/2;
        if(a[m]==k){
            return m;
        }
        else if(a[m]<k){
            return bin_search(l,m-1,k);
        }
        else if(a[m]>k){
            return bin_search(m+1,h,k);
        }


    }
    return -1;

}

int main(){

    
    int n = 10;
    int m,h,l;
    l = 0;
    h = n;
    int k;
    cout<<"enter key: ";
    cin>>k;
    int f =0;

    while(l<h){
        m = (l+h)/2;
        if(a[m]==k){
            cout<<" found at "<<m;
            f++;
            break;
        }
        else if (a[m]>k)
        {
            h = m-1;
        }
        else{
            l = m+1;
        }

    }
    if(f==0){
        cout<<"not found";
    }
    int x = bin_search(l,h,k);
    cout<<x;






    return 0;
}