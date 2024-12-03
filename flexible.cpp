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
#include <iomanip>

using namespace std;

typedef vector<int> vi;
typedef pair<double, double> ii;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;
typedef unordered_set<int> uset;
typedef unordered_map<int, int> umap;
typedef vector<bool> vb;
typedef vector<string> vs;


#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n){ cout << x << " ";} cout << endl;;
#define SORT(v) sort(v.begin(), v.end());

int main() {
    int w, p;
    cin  >> w >> p;
    vi v(p);
    in(p, v);
    v.push_back(w);
    v.push_back(0);
    SORT(v);
    uset dist;
    for(int i = 0; i < v.size(); i++){
        for(int j = i+1; j<v.size(); j++){
            dist.insert(abs(v[i]-v[j]));
        }
    }
    vi n;
    for(int x : dist){
        n.push_back(x);
    }
    SORT(n);
    print(n);


}
