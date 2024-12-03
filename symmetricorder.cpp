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
typedef vector<string> vs;


#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n){ cout << x; cout << endl;};
#define SORT(v) sort(v.begin(), v.end());

void solve(int c){
    return;
    
}

int main() {
    int n;
    cin >> n;
    int i = 1;
    string s;
    while(n != 0){
        vs v1;
        vs v2;
        bool first = true;
        FOR(n){
            cin  >> s;
            if(first) v1.push_back(s);
            else v2.push_back(s);
            first = !first;
        }
        reverse(v2.begin(), v2.end());
        v1.insert(v1.end(), v2.begin(), v2.end());
        cout << "SET " << i << endl;
        for(string g : v1){
            cout << g << endl;
        }
        cin >> n;
        i++;
    }
    return 0;
}
