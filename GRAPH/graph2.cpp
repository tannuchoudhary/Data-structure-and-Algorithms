/*We are going to make a graph of cities and then print their adjacency list that each city is
connected with how many cities and we will print them.

for that we are going to use map which will store the cities in the form of key and we will use
 linked list to store the list of the cities from the the former is connected
 i.e map<string list<string> >
 */
#include<iostream>
#include<map>
#include<list>
#include<cstring>
using namespace std;

//we are using templates for generic type
template<typename T>
class graph{
  map<T, list<T> > adjacencyList;
  //we have a map of type T in which key is of type T and value is of type of list of type T.
public:
 graph(){

 }
  void addEdge(T u, T v, bool bidir = true){
    adjacencyList[u].push_back(v);
    if(bidir){
      adjacencyList[v].push_back(u);
    }
  }

  void printAdjList(){
    for(auto row : adjacencyList){ //iterating over each row
     T key = row.first;    //print the keys
      cout<<key<<"->";
      for(T element : row.second){//print all the values of the respective keys
         cout<<element<<",";
      }
      cout<<endl;
    }
  }
};

int main(){
  graph<string>g;

  g.addEdge("Jharkhand", "Punjab");
  g.addEdge("Jharkhand", "Delhi");
  g.addEdge("Jharkhand", "UP");
  g.addEdge("UP", "Delhi");
  g.addEdge("Punjab","Delhi");
  g.addEdge("UP", "Punjab");


  g.printAdjList();

  return 0;
}
