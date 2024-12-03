#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#define vi vector<int>
#define vii vector<vector<int> >
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;


int main() {
    int n;
    cin >> n;
    if(n < 100){
        cout << 99 << endl;
        return 0;
    }
    //for a given number x - round it up and subtract 1, round it down and subtract 1
    //check which is clsoer
    //if both distance same - cout the up one
    // Round down to the nearest 100
    int down = (n / 100) * 100;
    down--;
    int down_d = abs(n-down);

    // Round up to the nearest 100
    int up = ((n + 99) / 100) * 100;
    up--;
    int up_d = abs(n-up);
    if(down_d < up_d){
        cout << down << endl;
    }
    else cout << up << endl;
    return 0;
}
