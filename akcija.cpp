#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <climits>
#define vi vector<int>
#define vii(n, m) vector<vector<char> > v(n, vector<char>(m, ' '))
#define viin vector<vector<int> > 
#define us unordered_set<int>
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;

int solve(vi v, int i = 0){
    reverse(v.begin(), v.end());
    for(int j = 0; j<i; j++){
        v.pop_back();
    }
    //v is 3 3 2
    //v is 6 5 5 5 5 4 
    int c = 0;
    for(int j = 0; j<v.size(); j+=3){
        c += v[j] + v[j+1];
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    vi v(n);
    in(n, v) //input taken
    sort(v.begin(), v.end());
    int cost = 0;
    //if n is not a multiple of 3 pay for the lowest 2 books anyways
    if(n%3 == 1){
        cout << v[0] + solve(v, 1) << endl; 
    }
    else if(n%3 == 2){
        cout << v[0] + v[1] + solve(v, 2) << endl;
    }
    else{
        cout << solve(v) << endl;
    }
    return 0;

}