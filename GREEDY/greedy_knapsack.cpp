#include<iostream>
#include<algorithm>

using namespace std;
struct item{            //This is a structure to contain profit and weight of objects
  float profit, weight;
};
bool cmp(item d1, item d2){ //comparison function for descending order
  int r1 = d1.profit / d1.weight; //sorting profit by weight ratio.
  int r2 = d2.profit / d2.weight;
  return r1 > r2;
}
float knapsack(float m,struct item a[], int size){
  sort(a, a+size, cmp);    //sort fuction for sorting in descending order.
  cout<<"Your data after sorting"<<endl;
  cout<<"PROFIT | WEIGHT | PROF/WT"<<endl;
  for(int k=0; k<size; k++){
    cout<<"    "<<a[k].profit<<"    "<<a[k].weight<<"    "<<a[k].profit/a[k].weight<<endl;
  }
  float current = 0.00;   //current weight filled in knapsack.
  float profit = 0.00;   //Final maximum profit.
  float remain;         //Remaining weight in knapsack.
  for(int i=0; i<size; i++){
    if(current + a[i].weight <= m){  //If there is space in the knapsack for filling the object fully then proceed

      current += a[i].weight; //increase the current weight
      profit += a[i].profit; //increase the profit
    }
    else{                    //When we want to keep fraction of object in knapsack.
      remain = m - current;
      profit += a[i].profit * remain/a[i].weight;
      break;
    }
  }
  cout<<endl<<"Your maximum profit will be ";
  return profit;
}
int main(){
  float m = 15.00; //This is the capacity of knapsack.
  item a[] = {{10, 2}, {5,3}, {15, 5}, {7, 7}, {6, 1}, {18, 4}, {3, 1}};//Items in the knapsack i.e, profit along with it's corresponding weight.
  int size = sizeof(a) / sizeof(a[0]);
  cout<<"PROFIT | WEIGHT | PROF/WT"<<endl;
  for(int i=0; i<size; i++){
    cout<<"    "<<a[i].profit<<"    "<<a[i].weight<<"    "<<a[i].profit/a[i].weight<<endl;
  }
  cout<<knapsack(m, a, size)<<endl;
  return 0;
}

