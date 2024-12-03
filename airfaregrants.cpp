#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
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


int main() {
    int n;
    cin >> n;
    vi v(n);
    FOR(n){
        cin >> v[i];
    }
    int r = *min_element(v.begin(), v.end());  //150
    int c = *max_element(v.begin(), v.end())/2;  //250
    if(r-c < 0) cout << 0 << endl;
    else cout << r-c << endl;
    return 0;
}
