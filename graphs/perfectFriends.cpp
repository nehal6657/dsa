#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
typedef vector<int> vi;
int N;
map<int, vector<int>> m1; //adjacency list
void bfs(int x){
    vector<int> visited(N+1,0);
    queue<int> s={};
    s.push(x);
    while(!s.empty()){
        int t = s.front();
        s.pop();
        if(!visited[t]){
            visited[t]=1;
            cout<<t<<" ";
        }
        vi tmp = m1[t];
        for(auto i: tmp){
            if(!visited[i])
                s.push(i);
        }
    }

}
void dfs(int x){
    vector<int> visited(N+1,0);
    stack<int> s={};
    s.push(x);
    while(!s.empty()){
        int t = s.top();
        s.pop();
        if(!visited[t]){
            visited[t]=1;
            cout<<t<<" ";
        }
        vi tmp = m1[t];
        for(auto i: tmp){
            if(!visited[i])
                s.push(i);
        }
    }

}

void recDFS(int x, vector<int> &Vis, vector<int> &v,int &m){
    Vis[x]=1;
    m++;
    v.push_back(x);
    for(auto i: m1[x]){
        if(!Vis[i]){
            recDFS(i, Vis,v,m);
        }
    }
    return;

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
    //dfs(1);
    cout<<endl;
    //bfs(1);
    vector<int> conn={};
    vector<vector<int>> conncomp;
    vector<int> Vis(N+1,0);
    for(int i=1;i<n;i++){
        if(!Vis[i]){
            vector<int> v={};
            int m = 0;
            recDFS(i,Vis,v, m);
            conncomp.push_back(v);
            conn.push_back(m);
        }
    }
    long long int ans = 0;
    for(int i=0;i<conn.size();i++){
        for(int j = i+1; j<conn.size();j++){
            ans += conn[i]*conn[j];
        }
    }
    cout<<ans<<endl;
    for(auto i: conncomp){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    
    return 0;


}


