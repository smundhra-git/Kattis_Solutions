#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

#define vi vector<int>
#define FOR(n) for(int i = 0; i<n; i++)

int main(){
    string x;
    cin >> x;
    stack<char> s;
    FOR(x.size()){
        if(x[i] == '<'){
            s.pop();
        }
        else{
            s.push(x[i]);
        }
    }
    x = "";
    while(!s.empty()){
        x += s.top();
        s.pop();
    }
    reverse(x.begin(), x.end());
    cout << x << endl;
}