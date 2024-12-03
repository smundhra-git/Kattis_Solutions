#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int Max(vector<int>& v){
  int pos = 0;
  int val = 0;
  for(int i = 0; i < v.size(); i++){
    if(v[i] > val){
      val = v[i];
      pos = i;
    }
  }
  return pos;
}

int Second_Max(vector<int>& v){
  int pos = 0;
  int val = 0;
  int max_pos = Max(v);
  if(max_pos == 0)
    pos = 1;
  
  for(int i = 0; i < v.size(); i++){
    if(i != max_pos && v[i] > val){
      val =v[i];
      pos = i;
    }
  }
  return pos;
}

int main(){
  int n;
  cin >> n; 
  vector<int> coins(n);
 
  int total = 0;
  for(int i = 0; i < n; i++){
    cin >> coins[i];
    total = total + coins[i];
  }
  if(total%2 == 1)
    cout << "no" << endl;
  else{
    // cout << "yes" << endl;
    stringstream output;
    bool possible =true;
    while(total > 0 && possible){
      int first = Max(coins);
      int second = Second_Max(coins);
      if(coins[second] == 0)
	possible = false;
      else{
	output << first+1 << " " << second+1 << "\n ";
	coins[first]--;
	coins[second]--;
	total = total -2;
      }
    }
    if(possible){
      cout << "yes" << endl;
      string s = output.str();
      cout << s << endl;
    }
    else
      cout << "no" << endl;
  }
  return 0;
}
  