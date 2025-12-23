#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void backtrack(int last) {
    if (!a.empty()) {
        int chan = 0, le = 0;
        for (int x : a) {
            if (x % 2 == 0) chan++;
            else le++;
        }

        if (chan > le) {
            for (int x : a) cout << x << " ";
            cout << "\n";
        }
    }

    for (int i = last + 1; i <= n; i++) {
        a.push_back(i);
        backtrack(i);
        a.pop_back();
    }
}

int main() {
    cin >> n;
    backtrack(0);
    return 0;
}
(Sinh tổ hợp và check in ra các tổ hợp có số các số chẵn nhiều hơn lẻ)