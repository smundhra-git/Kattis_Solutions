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
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vi trees(n);
    FOR(n){
        cin >> trees[i];
    }
    sort(trees.begin(), trees.end());
    reverse(trees.begin(), trees.end());
    FOR(n){
        trees[i] += 1 +i;
    }
    cout << *max_element(trees.begin(), trees.end())+1 << endl;


}
