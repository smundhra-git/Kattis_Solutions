#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <unordered_map>


using namespace std;



int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    vector<string> copy = v;
    sort(copy.begin(), copy.end());
    if(copy == v){
        cout << "INCREASING" << endl;
        return 0;
    }
    reverse(copy.begin(), copy.end());
    if(copy == v){
        cout << "DECREASING" << endl;
        return 0;
    }
    cout << "NEITHER" << endl;
    return 0;
}
