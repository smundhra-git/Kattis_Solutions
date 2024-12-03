#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cmath>
#define vi vector<int>
#define vii vector<vector<int> >
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;

int main() {
    long long x;
    cin >> x;

    int n = 0; // Maximum number of factors
    long long factor = 2; // Start with the smallest factor

    // Process all factors up to sqrt(x)
    while (factor * factor <= x) {
        while (x % factor == 0) {
            x /= factor; // Divide by the factor
            n++;         // Increment the count of factors
        }
        factor++; // Move to the next potential factor
    }

    // If x > 1, it must be a prime factor
    if (x > 1) {
        n++;
    }

    cout << n << endl;
    return 0;
}
