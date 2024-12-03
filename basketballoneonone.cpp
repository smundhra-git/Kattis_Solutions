#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

#define vi vector<int>
#define FOR(n) for(int i = 0; i<n; i=i+2)

int main(){
    string x;
    cin >> x;
    int scoreA = 0;
    int scoreB = 0;
    FOR(x.size()){
        if(x[i] == 'A'){
            scoreA += stoi(x.substr(i+1, 1));
        }
        else{
            scoreB += stoi(x.substr(i+1, 1));
        }
    }
    //score calculated
    cout << (scoreA > scoreB ? "A" : "B") << endl;
    return 0;
}