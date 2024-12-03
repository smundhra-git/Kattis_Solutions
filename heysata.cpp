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

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;
typedef unordered_set<string> uset;
typedef unordered_map<int, int> umap;
typedef vector<bool> vb;


#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(cur); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n){ cout << x.first << " " << x.second; cout << endl;};
#define SORT(v) sort(v.begin(), v.end());


int main() {
    int n;
    cin >> n;
    string k, s;
    cin >> k >> s;
    if(s.find(k) != string::npos) cout << "Unnar fann hana!" << endl;
    else cout << "Unnar fann hana ekki!" << endl;
    return 0;

}
