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
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(cur); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;
using namespace std;



int main() {
    int a, b, c;
    cin >> a >> b >> c;
    b = 2 * b;
    c = 3 * c;
    unordered_map<int, int> umap;
    FOR(3){
        int x, y;
        cin >> x >> y;
        for(int j = x; j< y; j++){
            umap[j]++;
        }
    }
    int cost = 0;
    for(auto x : umap){
        if(x.second == 1) cost += a; 
        else if(x.second == 2) cost += b;
        else if(x.second == 3) cost += c;
    }
    cout << cost << endl;

    return 0;
}
