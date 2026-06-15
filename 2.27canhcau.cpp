#include <bits/stdc++.h>
using namespace std;

int n;
int timer = 0;

vector<vector<int>> graph;
vector<int> disc, low, parent;
vector<bool> visited;
vector<pair<int,int>> bridges;

void DFS(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    
    for (int v : graph[u]) {
        if (!visited[v]) {
            parent[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                bridges.push_back({min(u, v), max(u, v)});
            }
        }
        
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    
    graph.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            
            if (x == 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    disc.resize(n + 1, 0);
    low.resize(n + 1, 0);
    parent.resize(n + 1, -1);
    visited.resize(n + 1, false);
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    
    sort(bridges.begin(), bridges.end());
    cout << bridges.size() << "\n";
    
    for (auto &bridge : bridges) {
        cout << bridge.first << ' '
        << bridge.second << "\n";
    }
    
    return 0;
}
