#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#define vi vector<int>
#define vii(n, m) vector<vector<char> > v(n, vector<char>(m, ' '))
#define viin vector<vector<int> > 
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 1; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;

//check if all letters are different
bool work(int n){
    string s = to_string(n);
    unordered_set<char> u;
    for(char c : s){
        if(u.find(c) != u.end()){
            return false;
        }
        u.insert(c);
    }
    if(u.find('0') != u.end()) return false;
    for(int i = 0; i<s.size(); i++){
        if(n%stoi(s.substr(i,1)) != 0) return false;
    }
    return true;
}

int main() {
    int l, h;
    cin >> l >> h;
    int count = 0;
    for(int i = l; i<h+1; i++){
        if(work(i)) count++;
    }
    cout << count << endl;
    return 0;   

}