#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int *visited;
int *parent;
int *discc;
int *min1;

int n,m; //no of  vertices, edges in the graph
map<int, vector<int>> m1; //adjacency list
vector<int> ap;  // stores articulation points 


int d = 1;  // discovery time of node in dfs
void dfs(int x){
    visited[x] = 1;
    discc[x]=min1[x] = d;
    d++;
    vector <int> v1 = m1[x];
    
    cout<<x<<" ";
    
    for(int i =0;i<v1.size();i++){
        if(visited[v1[i]]==0){
            parent[v1[i]] = x;
            dfs(v1[i]);
            min1[x]  = min(min1[x], min1[v1[i]]);

            // for root node
            if (parent[x] == 0 && v1.size() > 1){
                ap.push_back(x);
            }
            if (parent[x]!=0 && min1[v1[i]]>=discc[x]){
                ap.push_back(x);
            }
        }
        else if (v1[i]!=parent[x]){
            min1[x] = min(min1[x],discc[v1[i]]);
        }
        
    }
   

}

void articulationPoint(int x){


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
    // initailising required arrays;
    visited = new int[n+1];  // if the node is visited or not while traversal
    parent = new int[n+1];   // stores parent of node i
    discc = new int[n+1];    // stores discovery time of node i
    min1 = new int[n+1];     // stores minimum discovery number for every node i




    int x;

    cout<<"enter root: ";
    cin>>x;
    
    cout<<"dfs traversal of the graph is: ";
    dfs(x);
    cout<<"\n";

    // for(int i =0;i<n;i++){
    //     cout<<"parent of "<<i+1<<" is :"<<parent[i+1]<<"\n";
    // } cout<<"\n";
    // for(int i =0;i<n;i++){
    //     cout<<"discovery time of "<<i+1<<" is :"<<discc[i+1]<<"\n";
    // } cout<<"\n";
    // for(int i =0;i<n;i++){
    //     cout<<"minimum node that can be reached from "<<i+1<<" is :"<<min1[i+1]<<"\n";
    // } 

    cout<<"\nArticulation points are: ";
    for(int i =0;i<ap.size();i++){
        cout<<ap[i]<<" ";
    }



    return 0;
}