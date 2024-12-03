#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cmath>
#define vi vector<int>
#define vii(n, m) vector<vector<char> > v(n, vector<char>(m, ' '))
#define viin vector<vector<int> > 
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;

// returns the number of substrings in the range between l and r non-inclusive
long long Substrings_Between(int l,int r){
  long long dist = r-l-1;
  return (dist*(dist+1))/2;
  
}

int gcd(long long m, long long n){
  while(n != 0){
    long long temp = n;
    n = m%n;
    m = temp;
  }
  return m;
}

int main(){
  vector <string> string_list(1);
  string s;
  cin >> s;
  string_list[0] = s;

  int last_num = -1;
  vector<long long> counts(10,0);
  for(int i=9; i >=0; i--){
    // cout << "i = " << i << endl;
    vector<string> next_strings;
    for(int j = 0; j < string_list.size(); j++){
      int last_pos = -1;
      int next_pos = string_list[j].find(i+'0',last_pos+1);
      vector<int> positions;
      positions.push_back(-1);
      while(next_pos != string::npos){
	positions.push_back(next_pos);
	string slice = string_list[j].substr(last_pos+1, next_pos-last_pos-1);
	//	cout << "New slice: " << slice << endl;
	next_strings.push_back(slice);
	last_pos = next_pos;
	next_pos = string_list[j].find(i+'0', last_pos+1);
      }
      string slice = string_list[j].substr(last_pos+1);
      // cout << "New slice: " << slice << endl;
      next_strings.push_back(slice);
      positions.push_back(string_list[j].size());
      // The number of substrings that use this number is all of the
      // substrings possible EXCEPT the ones that are in between occurrences of
      // the number
      long long count = Substrings_Between(-1, string_list[j].size());
      for(int k = 0; k < positions.size()-1; k++){
	count -= Substrings_Between(positions[k], positions[k+1]);
      }
      counts[i] += count;
      // cout << "counts[" << i << "] now " << counts[i] << endl;
    }

    string_list = next_strings;
  }
  long long num = 0;
  for(int i = 0; i < 10; i++){
    // cout << "adding " << counts[i] << " " << i <<  "'s" << endl;
    num = num + counts[i]*i;
  }
 
  long long den = (s.size()*(s.size()+1))/2;
  //cout << "fraction: " << num << "/" << den << endl;
  long long whole = num/den;
  num = num-whole*den;
  int factor = gcd(num, den);
  if(whole > 0 || num == 0)
    cout << whole << " ";
  if(num > 0)
    cout << num/factor <<"/" << den/factor << endl;
  else
    cout << endl;
  return 0;
}
