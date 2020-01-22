#include<iostream>
#include<bits/stdc++.h>
#define V 9
using namespace std;
class edge{
public:
  int source;
  int dest;
  int weight;
};

int minvertex(int *dist, bool *visited){
  int index, min= INT_MAX;
  for(int i=0; i<V; i++){
    if((!visited[i])&&(dist[i]<min)){
      min = dist[i];
      index=i;
    }
  }
  return index;
}

void dijkstra(int graph[V][V], int src){
  int *dist = new int[V];//will keep the shortest distance between the vertex and the source
  bool *visited = new bool[V];//will keep the data whether the node is visited or not
  for(int i=0; i<V; i++){
    dist[i] = INT_MAX;
    visited[i] = false;
  }

  dist[src]=0; //distance between source and source is 0
  for(int i=0; i<V-1; i++){
    int u = minvertex(dist, visited); //pickup the minimum vertex among all the visited ones
    visited[u] = true;
    for(int j=0; j<V; j++){
      if((graph[u][j]!=0)&&(!visited[j])){//find all the neighbours of the picked up vertex and check if it is minimum and not visited
        int distance = dist[u]+graph[u][j];
        if(distance<dist[j]){
          dist[j] = distance;
        }
      }
    }
  }

for(int k=0; k<V; k++){
  cout<<k<<" "<<dist[k]<<endl;
}
}
int main(){
  int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  dijkstra(graph, 0);
  return 0;
}
