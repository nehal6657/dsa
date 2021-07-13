#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int visited[100005] = {0};
int n,m; //no of  vertices, edges in the graph
map<int, vector<int>> m1; //adjacency list

void dfs(int x){
    visited[x] = 1;
    vector <int> v1 = m1[x];
    int s = v1.size();
    cout<<x<<" ";
    for(int i =0;i<s;i++){
        if(visited[v1[i]]==0){
            dfs(v1[i]);
        }
    }
}


int main(){

    
    // considering undirected graph

    cout<<"enter no of ele(nodes): ";
    cin>>n;

    cout<<"enter no of edges: ";
    cin>>m;

    // creating adjacency list for the graph
    for(int i =0 ; i<m; i++){
        int x,y;
        cin>>x>>y;
        m1[x].push_back(y);
        m1[y].push_back(x);        
    }

    int x;

    cout<<"enter root: ";
    cin>>x;
    
    cout<<"dfs traversal of the graph is: ";
    dfs(x);
    cout<<"\n";


    return 0;
}