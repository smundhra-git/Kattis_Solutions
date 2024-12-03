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
    string s;
    cin >> s;
    int awake = 0;
    int coffee = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '1'){
            awake++;
            coffee = 2;
        }
        else{
            if(coffee > 0){
                awake++;
                coffee--;
            }
        }
    }
    cout << awake << endl;
    return 0;
}
