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
    int r, c, rr, rc;
    cin >> r >> c >> rr >> rc;

    vector<vector<char> > ans;
    for(int i = 0; i<r; i++){
        vector<char> v;
        for(int j = 0; j<c; j++){
            char c;
            cin >> c;
            for(int k = 0; k < rc; k++){
                v.push_back(c);
            }
        }
        for(int l = 0; l < rr; l++){
            ans.push_back(v);
        }
    }
    for(auto x : ans){
        for(auto c : x){
            cout << c;
        }
        cout << endl;
    }
    return 0;


}
