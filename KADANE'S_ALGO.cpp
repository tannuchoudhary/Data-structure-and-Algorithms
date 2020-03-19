//KADANE'S ALGORITHM
//LARGEST SUM SUBARRAY

#include<bits/stdc++.h>
using namespace std;

int kadane(int ar[], int n){
    
    int current_max_ending=0;
    int best_so_far=0;
    
   for(int i=0; i<n; i++){
       if(ar[i]>0)
       current_max_ending+=ar[i];
       
       if(best_so_far<current_max_ending)
       best_so_far=current_max_ending;
       
       if(ar[i]<0){
           current_max_ending=0;
       }
       
   } 
   return best_so_far;
}

int main(){
    int n;
    cin>>n;
    int *ar = new int[n];
    
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    
    int ans = kadane(ar, n);
    cout<<ans;
    return 0;
}
