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



int main() {
    int g,r;
    cin >>g >> r;
    //consumer every r with a g
    int h = 0; //start h 0
    while(r > 0 && g > 0){
        h += 10;
        r--;
        g--;
    }
    if( g== 0){
        cout << h << endl;
        return 0;
    }
    while(g >= 3){
        h = h+10;
        g -= 3;
    }
    while(g >= 2){
        h += 3;
        g -= 2;
    }
    while(g >= 1){
        h++;
        g--;
    }
    cout << h << endl;
    return 0;


}