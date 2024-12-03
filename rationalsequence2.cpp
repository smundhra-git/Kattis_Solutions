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


int solve(int l, int r) {
    if(l == r) {
        return 1;
    }

    if(l > r) {
        return 2 * solve(l-r, r) + 1;
    }

    if(l < r) {
        return 2 * solve(l, r-l);
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cout << temp << " ";

        int l, r;
        cin >> l;
        cin.ignore();
        cin >> r;

        cout << solve(l, r) << endl;
    }
}