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
typedef pair<double, double> ii;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;
typedef unordered_set<string> uset;
typedef unordered_map<int, int> umap;
typedef vector<bool> vb;


#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(cur); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n){ cout << x.first << " " << x.second; cout << endl;};
#define MOD 1000000007


int main() {
    int h,v;
    cin >> h >> v;
    if(v <= 180){
        cout << "safe" << endl;
        return 0;
    }
    double radians = v * M_PI / 180.0;
    double vertical_speed = -sin(radians);
    if (vertical_speed == 0) { // Avoid division by zero
        cout << "safe" << endl;
    } else {
        // Time to crash
        int time_to_crash = floor(h / vertical_speed);
        cout << time_to_crash << endl;
    }
    return 0;
}