#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

#define pii pair<int,int>
#define vp vector<pii>
#define vi vector<int>
#define FOR(n) for(int i = 0; i<n; i++)

const int t = 4;

using namespace std;

void solve(){
    int r, e, c;
    cin >> r >> e >> c;
    //revenue of advertise -> r
    e = e - c; //cost less
    if(r > e) cout << "do not advertise" << endl;
    else if(e > r) cout << "advertise" << endl;
    else cout << "does not matter" << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    while(n > 0){
        solve();
        n--;
    }

    
}
