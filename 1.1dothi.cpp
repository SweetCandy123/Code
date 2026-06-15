#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;

    int a[105][105];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            int deg = 0;
            for (int j = 1; j <= n; j++)
                deg += a[i][j];

            cout << deg;
            if (i < n) cout << " ";
        }
        cout << "\n"; 
    }
    else {
        vector<pair<int,int>> edges;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i][j] == 1) {
                    edges.push_back({i, j});
                }
            }
        }

        cout << n << " " << edges.size() << "\n";

        for (auto &e : edges) {
            cout << e.first << " " << e.second << "\n";
        }
    }

    return 0;
}

