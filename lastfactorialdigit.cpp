#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

#define pii pair<int,int>
#define vp vector<pii>
#define vi vector<int>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int fact = 1;
    for(int i = 1; i<n+1;i++){
        fact = fact * i;
    }
    string s = to_string(fact);
    cout << s[s.size()-1] << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while(t > 0){
        solve();
        t--;
    }
    return 0;
}
