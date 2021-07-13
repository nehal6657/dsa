#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

vs mazeE(int sx,int sy,int dx,int dy){
    if(sx==dx && sy==dy) {
        vs vx ={""}; return vx;
    } 
    vs hz,vt,diag;    vs ans;
    for(int x1 = 1; dx-x1 >= sx;x1++){
        hz = mazeE(sx+x1,sy,dx,dy);
        for(auto i: hz){
            string c = "h";
            c = c + to_string(x1);
            ans.push_back(c+i);
        }
    }
    for(int y1 = 1; dy-y1 >= sy;y1++){
        vt = mazeE(sx,sy+y1,dx,dy);
        for(auto i: vt){
            string c = "v";
            c = c + to_string(y1);
            ans.push_back(c+i);
        }
    }
    for(int d1 = 1; dy-d1 >= sy && dx-d1 >= sx;d1++){
        diag = mazeE(sx+d1,sy+d1,dx,dy);
        for(auto i: diag){
            string c = "d" ;
            c = c + to_string(d1);
            
            //cout<<"c="<<c<<" ";
            ans.push_back(c+i);
        }
    }
    return ans;
}

void pmaze2(int sx,int sy,int dx,int dy,string s){
    if(sx==dx && sy==dy){
        cout<<s<<" ";
        return;
    }
    if(sx>dx || sy>dy) return;
    for(int x1 = 1; dx-x1 >= sx;x1++){
        pmaze2(sx+x1,sy,dx,dy,s +"h"+ to_string(x1));
    }
    for(int y1 = 1; dy-y1 >= sy;y1++){
        pmaze2(sx,sy+y1,dx,dy,s +"v"+ to_string(y1));
        
    }
    for(int d1 = 1; dy-d1 >= sy && dx-d1 >= sx;d1++){
        pmaze2(sx+d1,sy+d1,dx,dy,s +"d"+ to_string(d1));
    }


}

int main(){
    vs ans1 = mazeE(1,1,3,3);
    for(auto i: ans1) cout<<i<<" ";
    cout<<"nehal\n";
    pmaze2(1,1,3,3,"");

    return 0;
}