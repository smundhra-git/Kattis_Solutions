#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, p, q;
    cin >> n >> p >> q;
    //number of server which has happened
    int serves = (p + q)/n;

    // Determine whose turn it is based on the parity of serves
    if (serves % 2 == 0) {
        cout << "paul" << endl;
    } else {
        cout << "opponent" << endl;
    }

    return 0;
}
