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

void generate_all(int k, unordered_set<string>& u, string s){
    if(s.size() == k){
        u.insert(s);
        return;
    }
    generate_all(k, u, s+'T');
    generate_all(k, u, s+'F');
    return;
}

int calc(string x, vector<string>& vs){
    int lowest = INT32_MAX;
    for(string s : vs){
        int score = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == x[i]) score++;
        }   
        lowest = min(lowest, score);
    }
    return lowest;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> ans(n);
    in(n, ans);
    //backtracking 
    //try all possible combinations of T/F on all cases
    unordered_set<string> u;
    generate_all(k, u, "");
    //on all cases go a loop to check the minimum score
    int ls = INT32_MIN;
    for(string x : u){
        ls = max(ls, calc(x, ans));
    }
    cout << ls << endl;




    return 0;
}
