/*TRAVELLING SALESMAN PROBLEM USING BITMASKING
THE IDEA IS , LET US ASSUME WE  HAVE FOUR CITIES A, B, C, D AND IF YOU VISIT CITY A THEN WE HAVE 0001 AND
AFTER THAT IF YOU WILL VISIT CITY C THEN YOU WILL HAVE 0101 AND AFTER VISITING ALL THE CITIES YOU WILL HAVE 1111,
1 AT EACH PLACE SHOWS THAT THE NODE IS VISITED
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n=4;
int dist[10][10]={       //THIS IS MY GRAPH
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}

};
int visited_all = (1<<n)-1; //THIS WILL GIVE 1111 THAT DOES MEAN ALL NODE IS VISITED, THIS IS THE BASE CONDITION
int tsp(int mask, int pos){//MASK GIVES THE DATA THAT HOW MANY NODES ARE VISITED TILL NOW
                          //AND POSITION GIVES YOU THE CURRENT POSITION

  if(mask == visited_all){
    return dist[pos][0];
  }
  int ans =INT_MAX;
  for(int city=0; city<n; city++){
    if((mask&(1<<city))==0){//WITH THE HELP OF THIS WE WILL FIND THAT WHETHER THE PARTICULAR CITY IS VISITED OR NOT
    int new_dist = dist[pos][city]+tsp(mask|(1<<city), city);//NEW DISTANCE IS EQUAL TO THE CURRENT CALCULATED DISTANCE AND ALL THE NEXT DISTANCES USING RECURSION
    ans = min(ans, new_dist);
    }
  }
  return ans;
}
int main(){
  cout<<"The minimum distance will be "<<tsp(1, 0)<<endl;
  return 0;

}
