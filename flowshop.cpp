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

int main() {
    int n, m; // n = number of swathers, m = number of stages
    cin >> n >> m;

    vvi p(n, vi(m));
    for (int i = 0; i < n; ++i) {
        vi temp(m);
        in(m, temp) p[i] = temp;
    }

    vi stageEndTime(m, 0); // Keeps track of when each stage is free
    vi completionTime(n, 0); // Keeps track of completion time for each swather

    for (int i = 0; i < n; ++i) {
        int currentSwatherTime = 0; // Time for the current swather to move through stages
        for (int j = 0; j < m; ++j) {
            currentSwatherTime = max(stageEndTime[j], currentSwatherTime) + p[i][j];
            stageEndTime[j] = currentSwatherTime;
        }
        completionTime[i] = currentSwatherTime;
    }

    for (int i = 0; i < n; ++i) {
        cout << completionTime[i] << " ";
    }
    cout << endl;

    return 0;
}