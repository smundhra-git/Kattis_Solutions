#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define vi vector<int>
#define vii vector<vector<int> >
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)

using namespace std;

// Function to convert a character to its base-62 value
int charToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';          // '0' to '9' -> 0 to 9
    else if (c >= 'a' && c <= 'z') return c - 'a' + 10; // 'a' to 'z' -> 10 to 35
    else if (c >= 'A' && c <= 'Z') return c - 'A' + 36; // 'A' to 'Z' -> 36 to 61
    return -1; // Invalid character (should not happen)
}

// Function to compare two base-62 integers
bool isSmallerInBase62(const string &a, const string &b) {
    // Compare lengths first (larger length means larger number)
    if (a.length() != b.length()) return a.length() < b.length();
    
    // Compare digit by digit if lengths are equal
    for (size_t i = 0; i < a.length(); i++) {
        if (charToValue(a[i]) != charToValue(b[i])) {
            return charToValue(a[i]) < charToValue(b[i]);
        }
    }
    // They are equal in base-62 representation (not possible per problem constraints)
    return false;
}

void solve() {
    string a, b;
    cin >> a >> b;

    // Nick's solution assumes lexicographical comparison
    bool nickSolution = (a < b);

    // Correct base-62 comparison
    bool correctSolution = isSmallerInBase62(a, b);

    // Output YES if Nick's solution is correct, otherwise NO
    if (nickSolution == correctSolution) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}