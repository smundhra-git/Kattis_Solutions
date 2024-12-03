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

void covert(string& s){
    //replace - with spaces
    auto pos = s.find("-");
    while(pos != string::npos){
        s[pos] = ' ';
        pos = s.find("-");
    }
    //lower case the whole word
    FOR(s.size()){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] - 'A' + 'a';
        }
    }
}

int main() {
    uset u;
    int n;
    cin >> n;
    cin.ignore();
    FOR(n){
        string k;
        getline(cin, k);
        covert(k);
        u.insert(k);
    }
    int count = 0;
    for(auto s : u) count++;
    cout <<  count << endl;
    return 0;
}