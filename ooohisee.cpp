#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
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
    int r, c;
    cin >> r >> c;
    vii(r, c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j<c; j++){
            cin >> v[i][j];
        }
    }
    int count = 0;
    viin pos;
    for(int i = 1; i<r-1;i++){
        for(int j = 1; j<c-1; j++){
            if(v[i][j] == '0'){
                if(v[i-1][j] == 'O' && v[i+1][j]  == 'O' && v[i][j+1]  == 'O' && v[i][j-1] == 'O' 
                && v[i-1][j-1] == 'O' && v[i-1][j+1]  == 'O' && v[i+1][j+1]  == 'O' && v[i+1][j-1] == 'O' ){
                    vi n;
                    n.push_back(i+1);
                    n.push_back(j+1);
                    pos.push_back(n);
                }
            }
        }
    }
    if(pos.size() == 0){
        cout << "Oh no!" << endl;
        return 0;
    }
    if(pos.size() > 1){
        cout << "Oh no! " << pos.size() << " locations" << endl;
    }
    else{
        cout << pos[0][0] << " "  << pos[0][1] << endl;
    }
    return 0;
    
    
}
