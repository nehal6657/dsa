#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

vs mazeE(int sx,int sy,int dx,int dy){
    if(sx==dx && sy==dy) {
        vs vx ={""}; return vx;
    } 
    vs hz,vt;
    if(sx<dx){
        hz = mazeE(sx+1,sy,dx,dy);
    }
    if(sy<dy){
        vt = mazeE(sx,sy+1,dx,dy);
    }
    vs ans;
    for(auto i: hz){
        ans.push_back('h'+i);
    }
    for(auto i: vt){
        ans.push_back('v'+i);
    }
    return ans;


}
void pmaze(int sx,int sy,int dx,int dy, string ans){
    if(sx==dx && sy==dy){
        cout<<ans<<" ";
        return;
    }
    if(sx>dx || sy>dy) return;
    if(sx < dx){
        pmaze(sx+1,sy,dx,dy,ans + "h");
    }
    if(sy < dy){
        pmaze(sx,sy+1,dx,dy,ans + "v");
    }
}


int main(){
    vs ans1 = mazeE(1,1,3,3);
    for(auto i: ans1) cout<<i<<" ";
    cout<<"nehal\n";

    pmaze(1,1,3,3,"");

    return 0;
}