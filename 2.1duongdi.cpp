#include <bits/stdc++.h>
using namespace std;

int n, u, v;
int a[101][101];

int countPath2() {
    int count = 0;
    for (int k = 1; k <= n; k++)
        if (a[u][k] && a[k][v])
            count++;
    return count;
}

vector<int> path;
bool visited[101];
bool found;

void dfs(int cur) {
    if (found) return;
    if (cur == v) {
        found = true;
        return;
    }
    
    for (int next = 1; next <= n; next++) {
        if (a[cur][next] && !visited[next]) {
            visited[next] = true;
            path.push_back(next);
            dfs(next);
            if (found) return;
            path.pop_back();
            visited[next] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    
    int t;
    cin >> t >> n >> u >> v;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    
    if (t == 1) {
        cout << countPath2() << "\n";
    } else {
        memset(visited, false, sizeof(visited));
        visited[u] = true;
        path.push_back(u);
        found = false;
        
        dfs(u);
        if (found) {
            for (int i = 0; i < (int)path.size(); i++) {
                if (i > 0) cout << " ";
                cout << path[i];
            }
            
            cout << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}
