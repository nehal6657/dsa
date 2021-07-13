#include<bits/stdc++.h>
using namespace std;
int visited[10]={0};
string res;
void perm(string s, int k){
    static string res=s;
    if(k==s.length()){
        cout<<res<<endl;
        
    }
    else{
        
        for(int i=0;i<s.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                res[k]=s[i];
                perm(s,k+1);
                visited[i]=0;
            }
        }
    }

}
int main(){
    perm("ABC",0);
    return 0;

    // string s ="abc"; // char s =['a','b','c','\0']
    // s ="a"; s=['a','\0'];
    // s ='a'; s=['a']


}
