#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
struct dj{
    bool visited;
    int cost;
    int parent;
    dj(){
        visited = false;
        cost = INT16_MAX;
        parent = -1;
    }
};
struct Graph
{
    int vertx;
    bool visited;
    int cost;
    int parent;

    Graph(int V){
        vertx = V;
        visited = false;
        cost = INT_MAX;
        parent = -1;
    }
};


struct cmp{
    bool operator()(const Graph &g1, const Graph &g2){
        return g1.cost < g2.cost;
    }
};
void dijkstra(int src, unordered_map<int, vector<pair<int,int>>> &m1){
    /*priority_queue<Graph, vector<Graph>, cmp> pq;
    pq.push(Graph(src));
    while(!pq.empty()){
        Graph gx = pq.top();
        pq.pop();
        for(pair<int,int> node: m1[gx.vertx]){


        }


    }*/
    


}


int main(){
    int V, E;
    cin>>V>>E;
    unordered_map<int, vector<pair<int,int>>> m1;
    for(int i=0;i<E;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        m1[x].push_back({y,wt});
        m1[y].push_back({x,wt});
    }
    int dist[V], cost[V],visited[V];

    for(int i=0; i < V; i++){
        dist[i] = INT_MAX;
        cost[i] = INT_MAX;
        visited[i] = false;
    }


    return 0;
}