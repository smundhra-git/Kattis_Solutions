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

int un(int a, int b, int c){
    if(a == b) return c;
    if(b == c) return a;
    return b;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int x, y;
    x = un(x1, x2, x3);
    y = un(y1, y2, y3);
    cout << x << " " << y << endl;
}


