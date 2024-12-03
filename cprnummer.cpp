#include <iostream>
using namespace std;
int main() {
    string x;
    cin >> x;
    int sum = stoi(x.substr(0,1))* 4 + stoi(x.substr(1,1)) * 3 + stoi(x.substr(2,1)) * 2 + stoi(x.substr(3,1)) * 7 +  stoi(x.substr(4,1)) * 6 + stoi(x.substr(5,1)) * 5 + stoi(x.substr(7,1))*4 + stoi(x.substr(8,1))*3 + stoi(x.substr(9,1))*2 + stoi(x.substr(10,1));
    if(sum % 11 == 0) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
  
}

