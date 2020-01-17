#include<iostream>
#include<list>
#include<queue>
using namespace std;

struct graph{
  int V;
  list<int> *adjacencyList;
public:
  graph(int v){
    V =v;
    adjacencyList = new list<int>[V];
  }

  void addEdge(int u, int v, bool bidir=true){
    adjacencyList[u].push_back(v);
    if(bidir == true){
      adjacencyList[v].push_back(u);
    }
  }

  void printAdjList(){
    for(int i=0; i<V; i++){
      cout<<i<<"->";
      for(int node : adjacencyList[i]){
        cout<<node<<", ";
      }
      cout<<endl;
    }
  }

  void bfs(int src, int dest){
    queue<int> q; //The operation will be performed in queue
    bool *visited = new bool[V+1]{0};//This array will keep boolean data and will tell us whether the node is visited or not
    int *dist = new int[V+1]{0};//This will tell us the distanceof any node from source.
    int *parent = new int[V+1];//This will tell us the parent of the particular node.

    for(int i=0; i<V; i++){
      parent[i] = -1;
    }

    q.push(src); //push the source node into the queue
    visited[src] = true;

    while(!q.empty()){ //pop the node from queue which is in front
      int node = q.front();
      cout<<node<<" ";
      q.pop();

      for(int neighbour:adjacencyList[node]){//and then push the neighbours of the node into the queue if it is not visited and then mark it as visited
        if(!visited[neighbour]){
          q.push(neighbour);
          visited[neighbour]=true;
          dist[neighbour] = dist[node]+1;//Keep the distance of particular node from source into the distance array
          parent[neighbour] = node;//Parent of the neighbours of the node would be the node itself so, update the parent array
        }
      }
    }
  cout<<endl;
  //print all the shortest distance of every node from source
  for(int i=0; i<V; i++){
    cout<<i<<" node have distance "<<dist[i]<<endl;
  }
//print min distance between source and sestination
  cout<<"Minimum distance between source and destination is "<<dist[dest]<<endl;
//print that path which is giving the shortest distance between source and destination
  int temp = dest;
  while(temp!=-1){
    cout<<temp<<"<--";
    temp = parent[temp];
   }
  }
};


int main(){
  graph g(6);

  g.addEdge(0,1);
  g.addEdge(0,4);
  g.addEdge(1,2);
  g.addEdge(2,4);
  g.addEdge(2,3);
  g.addEdge(4,3);
  g.addEdge(3,5);

  g.bfs(0, 5);

  return 0;
}
