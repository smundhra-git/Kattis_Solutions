#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
#define in(n, v) for (int i = 0; i < n; i++) cin >> v[i];
using namespace std;

long long calc(vi& v1, vi& v2, int n) {
    long long x = 0;
    for (int i = 0; i < n; i++) {
        x += (long long)v1[i] * v2[i];
    }
    return x;
}

void solve(int cur) {
    int n;
    cin >> n;
    vi v1(n), v2(n);
    in(n, v1);
    in(n, v2);

    // Sort arrays for minimum dot product
    sort(v1.begin(), v1.end());      // Ascending order
    sort(v2.begin(), v2.end(), greater<int>()); // Descending order

    long long min_dot_product = calc(v1, v2, n);

    cout << "Case #" << cur << ": " << min_dot_product << endl;
}

int main() {
    // Optimize input/output
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int cur = 1; cur <= t; cur++) {
        solve(cur);
    }
    return 0;
}