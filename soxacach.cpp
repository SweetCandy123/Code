#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

void backtrack(int last) {
    // In một dãy hợp lệ (ít nhất 1 phần tử)
    if (!a.empty()) {
        for (int x : a) cout << x << " ";
        cout << "\n";
    }

    // Thử các số tiếp theo
    for (int i = last + 1; i <= n; i++) {
        // Kiểm tra điều kiện xa cách
        if (a.empty() || abs(i - a.back()) > k) {
            a.push_back(i);
            backtrack(i);
            a.pop_back();
        }
    }
}

int main() {
    cin >> n >> k;
    backtrack(0);
    return 0;
}
(Số xa cách: nhập n, k sinh tổ hợp check hiệu các phần tử lớn hơn k không)