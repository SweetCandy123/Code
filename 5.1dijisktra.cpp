#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    
    int n, s, t;
    cin >> n >> s >> t;
    
    vector<vector<int>> c(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    
    // Dijkstra
    vector<int> dist(n + 1, INF);
    vector<int> prev(n + 1, -1);
    vector<bool> visited(n + 1, false);
    
    dist[s] = 0;
    
    for (int iter = 0; iter < n; iter++) {
        // Tìm d?nh chua tham có dist nh? nh?t
        int u = -1;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        
        if (u == -1 || dist[u] == INF) break;
        visited[u] = true;
        
        // C?p nh?t các d?nh k?
        for (int v = 1; v <= n; v++) {
            if (v == u) continue;
            if (c[u][v] == 10000) continue; // không có c?nh
            if (dist[u] + c[u][v] < dist[v]) {
                dist[v] = dist[u] + c[u][v];
                prev[v] = u;
            }
        }
    }
    
    if (dist[t] == INF) {
        cout << 0 << "\n";
    } else {
        cout << dist[t] << "\n";
        
        // Truy v?t du?ng di
        vector<int> path;
        for (int v = t; v != -1; v = prev[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        
        for (int i = 0; i < (int)path.size(); i++) {
            if (i > 0) cout << " ";
            cout << path[i];
        }
        cout << "\n";
    }
    
    return 0;
}
