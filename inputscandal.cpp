#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#define vi vector<int>
#define vii(n, m) vector<vector<char> > v(n, vector<char>(m, ' '))
#define viin vector<vector<int> > 
#define us unordered_set<int>
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 1; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;


int main() {
    string x;
    vector<string> v;
    while(getline(cin,x)){
        v.push_back(x);
    }
    cout << v.size() << endl;
    for(auto u : v){
        cout << u << endl;
    }

}
