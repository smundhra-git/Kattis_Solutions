#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

void solve(){
    int n;
    cin >> n;
    unordered_set<string> s;
    for(int i = 0; i<n; i++){
        string x;
        cin >> x;
        s.insert(x);
    }
    int count = 0;
    for(auto x : s){
        count++;
    }
    cout << count << endl;
}

int main(){
    int t;
    cin >> t;
    while(t > 0){
        solve();
        t--;
    }
    return 0;
}
