#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef pair<double, double> ii;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;
typedef unordered_set<int> uset;
typedef unordered_map<int, int> umap;
typedef vector<bool> vb;


#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(cur); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n){ cout << x.first << " " << x.second; cout << endl;};

int main() {
    int r, n;
    cin >> r >> n;
    vb v(r+1, false);
    v[0] = true;
    FOR(n){
        int x;
        cin >> x;
        v[x] = true;
    }
    FOR(r+1){
        if(!v[i]){
            cout << i << endl;
            return 0;
        } 
    }
    cout << "too late" << endl;
    return 0;
}
