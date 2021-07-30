#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
typedef vector<int> vi;
int N;
map<int, vector<int>> m1; //adjacency list

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
    queue<int> bfss;
    bfss.push(0);
    int f = 0;
    while(!bfss.empty()){
        int s = bfss.front();
        bfss.pop();
        if(visited[s] == 1){
            f = 1;
            break;
        }
        visited[s] = 1;
        for(auto i: m1[s]){
            if(visited[i] == 0)
                bfss.push(i);
        }

    }
    cout<<f;
    cout<<endl;
    return 0;
}