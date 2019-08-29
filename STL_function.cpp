#include<iostream>
#include<vector> //Header for vector.
#include<string> //Header for string.
#include<utility>//Header for pair.
#include<set> //Header for set.
#include<map> //Header for map.
#include<algorithm>//Header for searching, sorting and other operations.
using namespace std;

int main(){
  cout<<"---------------------------------------------------------------"<<endl;
  cout<<"------------------VECTOR---------------------------------------"<<endl;

  vector<int>v(5);
  for(int i=0; i<5; i++){
    v[i] = i+1;
  }
//  vector<int>::iterator it;
  for(int it=v.begin(); it!=v.end(); it++){
    cout<<*it<<endl;
  }
cout<<"---------------------------------------------------------------"<<endl;
cout<<"---------------------------------------------------------------"<<endl;

cout<<"------------------------STRING---------------------------------"<<endl;

  string s = "tannu";
  string s1(s,3,2);
  string s2 = s.substr(2,4);
  cout<<s1<<endl;
  cout<<s2<<endl;
  cout<<s<<endl;
  if(s1.compare(s2) == 0)
  cout<<"strings are equal"<<endl;
  else
  cout<<"strings are not equal"<<endl;

cout<<"---------------------------------------------------------------"<<endl;
cout<<"---------------------------------------------------------------"<<endl;

cout<<"-----------------------PAIR------------------------------------"<<endl;
pair<int, char>p;
p=make_pair(1,'a');
pair<int,char>p2(2,'b');
cout<<p.first<<" "<<p.second<<endl;
cout<<p2.first<<" "<<p2.second<<endl;

cout<<"---------------------------------------------------------------"<<endl;
cout<<"---------------------------------------------------------------"<<endl;


cout<<"----------------------SET--------------------------------------"<<endl;
 set<int>s;
    int ar[] = {1,2,3,4,5,6,7};
    for(int i=0; i<7; i++){
    s.insert(ar[i]);
  }
  set<int> :: iterator it;
  for(it=s.begin(); it!=s.end(); it++)
  {
    cout<<*it<<endl;
  }
  if(s.find(5)==s.end())
  cout<<"element not found"<<endl;
  else
  cout<<"element found"<<endl;
  
cout<<"---------------------------------------------------------------"<<endl;
cout<<"---------------------------------------------------------------"<<endl;

cout<<"-----------------------MAP-------------------------------------"<<endl;
int arr[] = {a,b,d,f,};
map<int, int>m;
for(int i=0; i<7; i++)
{
  m[arr[i]] = m[arr[i]]+1;
}
map<int, int> :: iterator it;
for(it = m.begin(); it != m.end(); it++)
{
  cout<<it->first <<" : "<<it->second<<endl;
}
m.erase(1);
cout<<endl;
for(it = m.begin(); it != m.end(); it++)
{
cout<<it->first <<" : "<<it->second<<endl;
}


  return 0;
}
