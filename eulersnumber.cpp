#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <climits>
#include <iomanip> // for fixed and setprecision
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

vector<double> fact(10001);

void f(int n){
    fact[0] = 1.0;
    fact[1] = 1.0;
    for(int i = 2; i<n+1; i++){
        fact[i] = i*fact[i-1];
    }
}


int main() {
    int n;
    cin >> n;
    f(n); //populated f
    double ans = 0.0;
    for(int i = 0; i<n+1;i++){
        ans += double(1.0/fact[i]);
    }
    cout << fixed << setprecision(16) <<  ans << endl;
}

