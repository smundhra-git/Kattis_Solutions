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
#define FOR(char, n) for(int char = 0; char < n; char++)
#define print(n) for(auto x : n){ cout << x.first << " " << x.second; cout << endl;};
#define SORT(v) sort(v.begin(), v.end());

int check_horizontal(vector<vector<char> > t){
    FOR(i, 3){
        if(t[i][0] == t[i][1] && t[i][1] == t[i][2]){
            if(t[i][0] == 'O') return 0;
            else return 1;
        }
    }
    return -1;
}
int check_v(vector<vector<char> > t){
    FOR(i, 3){
        if(t[0][i] == t[1][i] && t[1][i] == t[2][i]){
            if(t[0][i] == 'O') return 0;
            else return 1;
        }
    }
    return -1;
}

int check_d(vector<vector<char> > t){
    if(t[0][0] == t[1][1] && t[1][1] == t[2][2]){
        if(t[0][0] == 'O') return 0;
        else return 1;
    }
    if(t[0][2] == t[1][1] && t[1][1] == t[2][0]){
        if(t[0][2] == 'O') return 0;
        else return 1;        
    }
    return -1;
}

bool c(vector<vector<char> > t){
    if(check_horizontal(t) == 0 || check_v(t) == 0 || check_d(t) == 0) return true;
    else return false;
}

int main() {
    vector<vector<char> > t(3, vector<char>(3));
    FOR(i, 3){
        FOR(j, 3){
            cin >> t[i][j];
        }
    }
    //0 is O won, else 1
    if(c(t)) cout << "Jebb" << endl;
    else cout << "Neibb" << endl;
    return 0;

}
