#include<bits/stdc++.h>
using namespace std;
//vector<int> lps;
void lpsarr(vector<int> &lps, string ptrn, int m){

    lps[0]=0;
    int i = 1, len = 0;
    while(i<m){
        if(ptrn[i]==ptrn[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len>0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

int kmp(vector<int> &lps, string s, string p, int n, int m){
    int i = 0, j = 0;
    int ans = -1;
    while(i<n){
        
        if(s[i]==p[j]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"pattern found at : "<<i-j<<endl;
            ans = i-j;
            j = lps[j-1];
        }
        else if(i<n && p[j]!=s[i]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i+=1;
            }
        }
    }
    return ans;
}
int main(){
    string ptrn;
    cin>>ptrn;
    int m = ptrn.length();
    vector<int> lps(m);
    lpsarr(lps,ptrn,m);
    cout<<endl<<ptrn<<endl;
    for(auto i:lps) cout<<i<<" ";
    cout<<endl;
    string s;
    cin>>s;
    cout<<endl;
    int ans = kmp(lps,s,ptrn,s.length(),m);


    return 0;
}