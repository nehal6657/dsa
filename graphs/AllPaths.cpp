#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
typedef vector<int> vi;
int N;


    vector<vector<int>> ans ={};
    void dfs(int x, vector<vector<int>>& graph, vector<int> &tmp, vector<int> &visited){
        const int N = graph.size();
        visited[x] = 1;
        tmp.push_back(x);
        if(x==N-1){
            ans.push_back(tmp);
        }
        for(int i=0;i<graph[x].size();i++){
            if(!visited[graph[x][i]]){
                dfs(graph[x][i], graph, tmp, visited);
            }
            
        }
        visited[x] =0;
        tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // graph is adj list 
        const int N = graph.size();
        vector<int> vis(N,0);
        ans.clear();
        vector<int> v= {};
        dfs(0,graph,v,  vis);
        return ans;
    
    }

int main(){

}


