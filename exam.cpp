#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#define vi vector<int>
#define vii(n, m) vector<vector<char> > v(n, vector<char>(m, ' '))
#define viin vector<vector<int> > 
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;


int main() {
    int C;
    cin >> C;

    string yourAnswers, friendAnswers;
    cin >> yourAnswers >> friendAnswers;

    int N = yourAnswers.size();
    int matchCount = 0; // Count of matching answers
    for (int i = 0; i < N; ++i) {
        if (yourAnswers[i] == friendAnswers[i]) {
            matchCount++;
        }
    }

    int mismatchCount = N - matchCount;
    int maxScore = min(C, matchCount) + min(N - C, mismatchCount);
    cout << maxScore << endl;

    return 0;
}
