/*I am going to implement prims algorithm, in prims we print minimum spanning tree
so you'll be given a graph and you have to find the mnimum weighted path to traverse all of the nodes, this is the meaning of
minimum spanning tree.

so your input would be something like this-
        { {0, 28, 0, 0, 0, 10, 0},
          {28, 0, 16, 0, 0, 0, 14},
          {0, 16, 0, 12, 0, 0, 0},
          {0, 0, 12, 0, 22, 0, 18},
          {0, 0, 0, 22, 0, 25, 24},
          {10, 0, 0, 0, 25, 0, 0},
          {0, 14, 0, 18, 24, 0, 0}
        }
        
This is the adjacency matrix of a graph of 7 nodes

Your output should be

PROCEDURE:
First of all you need three arrays, KEY, PARENT and MSTSET
KEY will store the length of each node of minimum spanning tree
PARENT will store the parent node of each node
MSTSET will store the data that whether the node has been visited or not

basically we will traverse through the graph, first of all keep first node as root node and then keep adding the neighbouring 
node each time which is of least length and are not visited 
*/

#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<algorithm>
using namespace std;
#define V 7 //define the  no of nodes in the graph

int minkey(int key[], bool mstset[]){
  int minimumkey = INT_MAX, minimumIndex;
  for(int i=0; i<V; i++){
    if(mstset[i] == false && key[i]<minimumkey){
      minimumkey=key[i];
      minimumIndex=i;
    }
  }
  return minimumIndex;
}
void printMST(int parent[], int graph[V][V]){
  cout<<"Edge       weight"<<endl;
  for(int i=1; i<V; i++){
    cout<<parent[i]<<"-"<<i<<"   "<<graph[i][parent[i]]<<endl;
  }
}
void prims(int graph[V][V]){
  int parent[V];//for storing parent
  int key[V];//for storing weight of edge of mst
  bool mstset[V];//it will keep the data whether the particular node is visited or not

  for(int i=0; i<V; i++){
    key[i] = INT_MAX;//put infinity in all the elements of key
    mstset[i] = false;//and in beginning all the nodes are unvisited
  }
  key[0] = 0;//take the first node and its wight will be 0
  parent[0] = -1;//as it is a root so parent is -1

  for(int i=0; i<V-1; i++){

    int u = minkey(key, mstset);//find minimum weight among all which is not visited
    mstset[u] = true;//mark it visited
    for(int v=0; v<V; v++){
      if(graph[u][v] && mstset[v]==false && (graph[u][v]<key[v])){//now find the node which is connected with the nodes which are in mst and have min wt and are not visited
        key[v]=graph[u][v];//put its wt in key
        parent[v]=u;//update the parent
      }
    }
  }
  printMST(parent, graph);
}
int main(){
  int graph[V][V] = {
          {0, 28, 0, 0, 0, 10, 0},
          {28, 0, 16, 0, 0, 0, 14},
          {0, 16, 0, 12, 0, 0, 0},
          {0, 0, 12, 0, 22, 0, 18},
          {0, 0, 0, 22, 0, 25, 24},
          {10, 0, 0, 0, 25, 0, 0},
          {0, 14, 0, 18, 24, 0, 0}
  };
/*  int graph[V][V] =   { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
                        */
  prims(graph);

return 0;
}
