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
    while (cin >> n) {
        vi v(n);
        in(n, v);
        if (n == 1) {
            cout << "Jolly" << endl;
            continue;
        }
        set<int> differences;

        // Calculate absolute differences and add to the set
        for (int i = 0; i < n - 1; i++) {
            differences.insert(abs(v[i + 1] - v[i]));
        }

        // Check if the differences are exactly {1, 2, ..., n-1}
        bool isJolly = true;
        for (int i = 1; i < n; i++) {
            if (differences.find(i) == differences.end()) {
                isJolly = false;
                break;
            }
        }

        if (isJolly) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}