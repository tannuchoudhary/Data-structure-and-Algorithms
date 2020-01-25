/*This is just like dijkstra, the difference is only that unlike dikstra, it will also contain negative weight
cycles and we will tell user that the graph contains negative weight cycles

for this first of all we will relax the edges v-1 times to find the shortest path, as we know that
at first relaxation it gives the path of all vertex from source which is one edge away and in second relaxation, it gives the shortest
path of the vertex which is 2 edges away, similarly for the final shortest path we relax the edges v-1 times.

and then we will relax the edges one more time, if this time it gives the shorter path then it contains negative weight cycle, we will
return from there.
*/
#include<iostream>
#include<limits.h>
using namespace std;

struct edge{
  int src, dest, wt;
};

struct Graph{
  int V, E;
  edge *Edge;
};

Graph* constructGraph(int v, int e){
  Graph *graph = new Graph;
  graph->V=v;
  graph->E=e;
  graph->Edge = new edge[e];
  return graph;
};

void print_array(int dist[], int V){
  cout<<"Vertex   Shortest Distance from source"<<endl;
  for(int i=0; i<V; i++){
    cout<<i<<"               "<<dist[i]<<endl<<endl;
  }
}

void bellman_ford(Graph *graph, int source){
  int V = graph->V;
  int E = graph->E;
  int dist[V];

  for(int i=0; i<V; i++){//This array will contain shortest distance of vertex from source
    dist[i] = INT_MAX;
  }
  dist[source]=0;

  for(int i=1; i<=(V-1); i++){ //relax all the edges v-1 times
    for(int j=0; j<E; j++){
      int u = graph->Edge[j].src;
      int v = graph->Edge[j].dest;
      int weight = graph->Edge[j].wt;

      if((dist[u]!=INT_MAX) && (dist[u]+weight<dist[v])){
        dist[v] = dist[u]+weight;
      }
    }
  }

  for(int j=0; j<E; j++){ //relax all the edge one more time
    int u = graph->Edge[j].src;
    int v = graph->Edge[j].dest;
    int weight = graph->Edge[j].wt;

    if((dist[u]!=INT_MAX) && (dist[u]+weight<dist[v])){
    cout<<"CONTAINS NEGATIVE WEIGHT CYCLE"<<endl;
    return;
    }
  }
  print_array(dist, V);
}

int main(){
  int V=5;
  int E=8;
  Graph *graph = constructGraph(V, E);

  graph->Edge[0].src = 0;
  graph->Edge[0].dest = 1;
  graph->Edge[0].wt = -1;

  graph->Edge[1].src = 0;
  graph->Edge[1].dest = 2;
  graph->Edge[1].wt = 4;

  graph->Edge[2].src = 3;
  graph->Edge[2].dest = 2;
  graph->Edge[2].wt = 5;

  graph->Edge[3].src = 4;
  graph->Edge[3].dest = 3;
  graph->Edge[3].wt = -3;

  graph->Edge[4].src = 1;
  graph->Edge[4].dest = 4;
  graph->Edge[4].wt = 2;

  graph->Edge[5].src = 1;
  graph->Edge[5].dest = 2;
  graph->Edge[5].wt = 3;

  graph->Edge[6].src = 3;
  graph->Edge[6].dest = 1;
  graph->Edge[6].wt = 1;

  graph->Edge[7].src = 1;
  graph->Edge[7].dest = 3;
  graph->Edge[7].wt = 2;

  bellman_ford(graph, 0);

  return 0;
}
