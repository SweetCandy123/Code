#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
	
	int t, n, m;
	cin >> t >> n >> m;
	
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
	vector<int> deg(n + 1, 0);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
		deg[u]++;
		deg[v]++;
	}
	
	if (t == 1) {
		for (int i = 1; i <= n; i++) {
			cout << deg[i];
			if (i < n) cout << " ";
		}
		cout << "\n";
	} else {
		cout << n << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << adj[i][j];
				if (j < n) cout << " ";
			}
			cout << "\n";
		}
	}
	
	return 0;
}	
