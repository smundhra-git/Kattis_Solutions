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
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 1; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;

// Function to compute nCr
long long binomialCoefficient(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    long long result = 1;
    for (int i = 1; i <= r; i++) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

void solve(){
    int n, k;
    cin >> n >> k;

    // Calculate the number of locks needed
    long long locks = binomialCoefficient(n, k - 1);
    cout << locks << endl;
}

int main() {
    mult(t);

    return 0;
}