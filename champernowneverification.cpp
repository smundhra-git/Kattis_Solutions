#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <random>

using namespace std;


int main() {
    string s;
    cin >> s;
    int cur = 1;
    int size = 1;
    while(s.size() != 0){
        int x = stoi(s.substr(0, size));
        if(x != cur){
            cout << -1 << endl;
            return 0;
        }
        s = s.substr(size, s.size()-size);
        cur++;
        size = to_string(cur).size();
    }   
    cout << cur - 1 << endl;
    return 0;

}
