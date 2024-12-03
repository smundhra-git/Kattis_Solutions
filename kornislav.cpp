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


int main() {
    int sides[4];
    
    // Input four integers
    for (int i = 0; i < 4; ++i) {
        cin >> sides[i];
    }
    
    // Sort the integers
    sort(sides, sides + 4);
    
    // The largest rectangle's area is the product of the smallest two and largest two
    int largestRectangle = sides[0] * sides[2];
    
    // Output the result
    cout << largestRectangle << endl;
    
    return 0;
}

