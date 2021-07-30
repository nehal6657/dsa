#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
typedef vector<int> vi;
int N;
map<int, vector<int>> m1; //adjacency list
vector<vector<int>> hampaths;
void HamPath(int x, vector<int> &visited,int &c, vector<int> &path){
    visited[x] = 1;
    c++;
    path.push_back(x);
    if(path.size() == N){
        hampaths.push_back(path);
    }
    for(auto i: m1[x]){
        if(!visited[i]){
            HamPath(i,visited,c,path);
        }
    }
    visited[x]=0;
    path.pop_back();

}

int main(){
    int n,m;
    // considering undirected graph
    cout<<"enter no of ele(nodes): ";
    cin>>n;
    cout<<"enter no of edges: ";
    cin>>m;
    N = n;

    // creating adjacency list for the graph
    for(int i =0 ; i<m; i++){
        int x,y;
        cin>>x>>y;
        m1[x].push_back(y);
        m1[y].push_back(x);    
    }
    
    vector<int> visited(N,0);
    for(int i=0;i<N;i++){
        int c= 0;
        vector<int> path = {};
        HamPath(i, visited, c, path);
        
    }
    for(auto i: hampaths){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}