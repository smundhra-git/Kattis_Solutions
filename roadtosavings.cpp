#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int shortest_distance = INT_MAX;
int counter = 0;

void print_2d(const vector<vector<int> >& v) {
    for(int i = 0; i<v.size(); i++) {
        for(int j = 0; j<v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int minDistance(const vector<int>& dist, const vector<bool>& visited) {
    int min_index = -1, min_distance = INT_MAX;
    for (int i = 1; i < dist.size(); i++) {
        if (!visited[i] && dist[i] < min_distance) {
            min_distance = dist[i];
            min_index = i;
        }
    }
    return min_index;
}


void count(vector<vector<int> >& v){
    int total = 0;
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[i].size(); j++){
            total = total + v[i][j];
        }
    }
    cout << total/2 << endl;
}

void Djikstra(vector<vector<int> > input, int a, int b) {
    try {
        counter++;
        int n = input.size() - 1;
        vector<int> dist(n + 1, INT_MAX); 
        vector<bool> visited(n + 1, false); 
        vector<int> parent(n + 1, -1); 
        dist[a] = 0; 

        for (int count = 1; count <= n; count++) {
            int u = minDistance(dist, visited);
            if(u == -1) break; 
            visited[u] = true;

            for (int v = 1; v <= n; v++) {
                if (!visited[v] && input[u][v] && dist[u] != INT_MAX &&
                    dist[u] + input[u][v] < dist[v]) {
                    dist[v] = dist[u] + input[u][v];
                    parent[v] = u; 
                }
            }
        }

        if (dist[b] == INT_MAX) {
            count(input);
            return;
        } 
        else {
            //cout << "Shortest distance from " << a << " to " << b << " is " << dist[b] << endl;

            if(counter == 1) {
                shortest_distance = dist[b];
            }
            if(dist[b] > shortest_distance) {
                count(input);
                return;
         
            }

            // Print the path from 'a' to 'b'
            //cout << "Path: ";
            vector<int> path;
            int current = b;
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            for (int i = path.size() - 1; i >= 0; i--) {
                //cout << path[i];
                if (i > 0) {
                    //cout << " -> ";
                }
            }
            //cout << endl;
            
            // Reset edges on the path
            for(int i = path.size()-1; i >= 1; i--){
                input[path[i]][path[i-1]] = 0;
                input[path[i-1]][path[i]] = 0;
            }
            
            Djikstra(input, a, b);
        }
    }
    catch(...) {
        cerr << "An error occurred." << endl;
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    vector<vector<int> > input(n+1, vector<int>(n+1, 0));
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        input[t1][t2] = t3;
        input[t2][t1] = t3;
    }

    Djikstra(input, a, b);
    return 0;
}
