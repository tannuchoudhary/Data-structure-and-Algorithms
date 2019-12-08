#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct jobSWD{
  char job;
  int profit;
  int deadline;
};
bool compare(jobSWD j1, jobSWD j2){ //boolean function for returning the greater one.
  return (j1.profit > j2.profit);  //as we are sorting the profit.
}
void jobSeqWithDdln(jobSWD a[], int);
void jobSeqWithDdln(jobSWD arr[], int size){
  sort(arr, arr+size, compare); //using STL for sorting the profit in descending order
  int result[size];             //It will keep the final result
  bool slot[size];              //It will keep the status of a space whether it is vacant or filled.
  memset(slot, false, size);    //memset function for assigning false in each slot initially.

//for (int i=0; i<size; i++)
  //      slot[i] = false;

  for(int i=0; i<size; i++){ //iterating for each job
    for(int j=min(size, arr[i].deadline)-1; j>=0; j--){//finding a place for job in result array
      if(slot[j]==false){ //if slot is false that does mean it is empty
        result[j] = i; //assign the job index
        slot[j] = true; //and mark it filled
        break;
      }
    }
  }
  for(int i=0; i<size; i++){ //finally print your job sequence.
    if(slot[i])
    cout << arr[result[i]].job <<" ";
  }
}

int main(){
  jobSWD arr[] = {{'a', 2, 3}, {'b', 4, 3}, {'c', 3, 3}, {'d', 1, 4}, {'e', 10, 4}};//This is our job and their corresponding profit and deadline.
  int size = sizeof(arr)/sizeof(arr[0]);
  jobSeqWithDdln(arr, size);
  return 0;
}
