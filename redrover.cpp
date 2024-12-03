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


#define in(n, v) for(int top = 0; top < n; top++) cin >> v[top];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n){ cout << x << endl;}
#define SORT(v) sort(v.begin(), v.end());

// Function to calculate the encoded length using a specific macro
int calculateEncodedLength(const string& route, const string& macro) {
    int macroLength = macro.size();
    int macroCount = 0;

    // Replace occurrences of the macro in the route with 'M'
    string encodedRoute = route;
    size_t pos = encodedRoute.find(macro);
    while (pos != string::npos) {
        macroCount++;
        encodedRoute.replace(pos, macroLength, "M");
        pos = encodedRoute.find(macro, pos + 1);
    }

    // Encoded length = length of the encoded route + length of the macro
    return encodedRoute.size() + macroLength;
}

int main() {
    string route;
    cin >> route;

    int n = route.size();
    int minLength = n; // Start with the original length as the worst case

    // Try every possible substring as a macro
    for (int len = 1; len <= n; len++) { // Length of the macro
        for (int start = 0; start + len <= n; start++) {
            string macro = route.substr(start, len);
            minLength = min(minLength, calculateEncodedLength(route, macro));
        }
    }

    cout << minLength << endl;
    return 0;
}