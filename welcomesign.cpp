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

#include <iostream>
#include <string>

using namespace std;

void solve(string s, int c, int r, bool& o1) {
    int n = s.size();  // Length of the string
    int k = c - n;  // Number of remaining columns to fill with dots

    if (n == c) {
        cout << s << endl;  // If the string length equals the total columns, print it as is
        return;
    }

    // Determine whether the current row is odd or even
    bool odd = (r % 2 != 0);
    
    // If the number of remaining spaces (k) is odd or even, the dots placement will change
    if (k % 2 == 0) {
        // Even number of remaining spaces (k), so evenly split dots around the string
        cout << string(k / 2, '.');  // Print dots before the string
        cout << s;  // Print the string itself
        cout << string(k / 2, '.');  // Print dots after the string
    } else {
        // Odd number of remaining spaces (k), place one more dot on the left if the row is odd
        if (o1) {
            cout << string(k / 2, '.');  // Dots before
            cout << s;  // The string itself
            cout << string(k / 2 + 1, '.');  // Dots after (one extra dot on the right)
            o1 = false;
        } else {
            cout << string(k / 2 + 1, '.');  // Dots before (one extra dot on the left)
            cout << s;  // The string itself
            cout << string(k / 2, '.');  // Dots after
            o1 = true;
        }
    }
    cout << endl;
}

int main() {
    int r, c;
    cin >> r >> c;  // Read the number of rows and columns
    bool o1 = true;
    FOR(r){
        string s;
        cin >> s;  // Read the string for the current row
        solve(s, c, i+1, o1);  // Call the solve function for each string and row index
    }

    return 0;
}
