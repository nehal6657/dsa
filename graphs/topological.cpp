#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
typedef vector<int> vi;
int N;

// topological sort code
void dfs(int x, vector<int> &visited,  stack<int> &s, vector<vector<int>> &m1){
    visited[x] = 1;
    for(int i = 0; i<m1[x].size();i++){
        if(!visited[m1[x][i]]){
            dfs(m1[x][i],visited,s,m1);
        }
    }
    s.push(x);
}
int main(){
    int n,m;

    // considering directed graph with 0- n-1 nodes

    cout<<"enter no of ele(nodes): ";
    cin>>n;

    cout<<"enter no of edges: ";
    cin>>m;


    N = n;
    // creating adjacency list for the graph
    vector<vector<int>> m1(n); //adjacency list
    for(int i =0 ; i<m; i++){
        int x,y;
        cin>>x>>y;
        m1[x].push_back(y);  
    }
    vector<int> visited(N,0);
    stack<int> s={};
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited, s,m1);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}


