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
typedef unordered_set<string> uset;
typedef unordered_map<int, int> umap;
typedef vector<bool> vb;
typedef vector<string> vs;


#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n){ cout << x.first << x.second; cout << endl;};
#define SORT(v) sort(v.begin(), v.end());

bool comp(ii a, ii b){
    if(a.second == b.second){
        return (a.first < b.first);
    }
    return (a.second < b.second);
}

int main() {
    double a, b, c, i, j, k;
    cin >> a >> b >> c >> i >> j >> k;
    double m = INT32_MAX;
    m = min(m, a/i);
    m = min(m, b/j);
    m = min(m, c/k);

    double r, q, s;
    r = a - (m * i);
    q = b - (m * j);
    s = c - (m * k);

    cout << fixed << setprecision(6); // To display results with precision
    cout << abs(r) << " ";
    cout << abs(q) << " ";
    cout << abs(s) << endl;



}
