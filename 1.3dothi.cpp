#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
	
	int t, n;
	cin >> t >> n;
	
	int a[105][105];
	
	for (int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	
	if (t == 1) {
		for (int i = 1; i <= n; i++) {
			int deg = 0;
			for(int j = 1; j <= n; j++)
				deg += a[i][j];
			
			cout << deg;
			if (i < n) cout << " ";
		}
		cout << "\n";
	}
	else {
		vector<pair<int,int>> edges;
		
		for (int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if (a[i][j] == 1) {
					edges.push_back({i, j});
				}
			}
		}
		
		int m = edges.size();
		
		cout << n << " " << m << "\n";
		
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < m; k++) {
				int u = edges[k].first;
				int v = edges[k].second;
				
				if (i == u || i == v)
					cout << 1;
				else
					cout << 0;
				
				if (k < m - 1) cout << " ";
			}
			cout << "\n";
		}
	}
	
	return 0;
}
