#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double g = 9.81;

double radian(double degree){
    // Convert degrees to radians
    return degree * M_PI / 180.0;
}

void solve(){
    double v0, angle, x1, h1, h2;
    cin >> v0 >> angle >> x1 >> h1 >> h2;

    double time = x1 / (v0 * cos(radian(angle)));
    double yt = (v0 * sin(radian(angle)) * time) - (0.5 * g * time * time);

    if ((yt + 1) < h2 && (yt - 1) > h1) {
        cout << "Safe" << endl;
    } else {
        cout << "Not Safe" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    while(n > 0){
        solve();
        n--;
    }
    return 0;
}
