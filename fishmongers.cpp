#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <climits>
#define vi vector<int>
#define vii(n, m) vector<vector<char> > v(n, vector<char>(m, ' '))
#define viin vector<vector<int> > 
#define us unordered_set<int>
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FishMarket {
    long long fish;  // Amount of fish they can buy
    long long money; // Bid amount per fish
};

// Comparison function for sorting bidders by money in descending order
bool compare(FishMarket a, FishMarket b) {
    return a.money > b.money;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> fish(n);
    for (int i = 0; i < n; i++) {
        cin >> fish[i];
    }

    // Sort fish in descending order
    sort(fish.begin(), fish.end(), greater<int>());

    vector<FishMarket> pq(m);
    for (int i = 0; i < m; i++) {
        cin >> pq[i].fish >> pq[i].money;
    }

    // Sort bidders by money in descending order
    sort(pq.begin(), pq.end(), compare);

    // Sell fish to the highest bidder
    int currentBidder = 0; // Index of the highest bidder
    long long maxRevenue = 0;

    for (int i = 0; i < fish.size(); i++) {
        maxRevenue += (fish[i] * pq[currentBidder].money);
        pq[currentBidder].fish--;

        // Move to the next bidder if the current bidder cannot buy more
        if (pq[currentBidder].fish == 0) {
            currentBidder++;
        }

        // Break if no bidders are left
        if (currentBidder >= pq.size()) {
            break;
        }
    }

    cout << maxRevenue << endl;
    return 0;
}
