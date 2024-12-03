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
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(cur); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin >> heights[i];

    unordered_map<int, int> active_arrows; // Tracks arrows at specific heights
    int arrows = 0;

    for (int height : heights) {
        if (active_arrows[height] > 0) {
            // If an arrow is already moving at this height, continue its journey
            active_arrows[height]--;
            active_arrows[height - 1]++;
        } else {
            // No arrow is available at this height; shoot a new one
            arrows++;
            active_arrows[height - 1]++;
        }
    }

    cout << arrows << endl;
    return 0;
}
