#include<bits/stdc++.h>
using namespace std;
int binaryStrings(int n){
    int c0=1,c1=1;
    for(int i =1;i<n;i++){
        
        //cout<<c0<<" "<<c1<<"\n";
        int nc0 = c1,nc1 = c0+c1;
        c0 = nc0;
        c1 = nc1;
        //cout<<c0<<" "<<c1<<"\n";
    }
    return c0+c1;   

}
int main(){
    int n;
    cin>>n;
    cout<<binaryStrings(n)<<endl;
    return 0;
}