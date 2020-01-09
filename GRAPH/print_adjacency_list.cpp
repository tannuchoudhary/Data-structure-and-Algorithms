#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

class graph{
  int V; //vertex or nodes
  list<int> *adjacencyList; //linked list for storing the adjacency list
public:
  graph(int v){
    V = v;
    adjacencyList = new list<int>[V];
  }

  void addEdge(int u, int v, bool bidir = true){ //add edge between u and v
    adjacencyList[u].push_back(v);
    if(bidir){
      adjacencyList[v].push_back(u);
    }
  }

  void printAdjList(){
    for(int i=0; i<V; i++){
      cout<<i<<"->";
      for(int node : adjacencyList[i]){  //using for each
        cout<<node<<",";
      }
      cout<<endl;
    }
  }
};

int main(){
  graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(1, 3);
  g.addEdge(3, 2);

  g.printAdjList();

  return 0;
}
