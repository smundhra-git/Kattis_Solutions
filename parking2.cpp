#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <climits>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;
typedef unordered_set<string> uset;
typedef unordered_map<int, int> umap;
typedef vector<bool> vb;


#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(); t--; cur++; }
#define FOR(char, n) for(int char = 0; char < n; char++)
#define print(n) for(auto x : n){ cout << x.first << " " << x.second; cout << endl;};
#define SORT(v) sort(v.begin(), v.end());



void solve(){
    int n;
    cin >> n;
    vi v(n);
    in(n, v)
    SORT(v)
    int min = v[0];
    int max = v[v.size()-1];
    cout << (max-min)*2 << endl;
    return;
}

int main() {
    mult(t)
}
