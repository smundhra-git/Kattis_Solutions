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

void solve() {
    string a, b;
    cin >> a >> b;

    FOR(b.size()){
        if(a.find(b[i]) == string::npos){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    mult(t);
    return 0;
}