
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        vector<long long> a (n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<long long> b (m);
        for (int i = 0; i < m; i++)
            cin >> b[i];
        long long sum = 0, cnt = 0, temp = 0, i = 0, j = 0;
        while (i < n and sum + a[i] <= x) {
            sum += a[i];
            i++;
        }
        cnt = i;
        while (j < m and i >= 0) {
            sum += b[j];
            j++;
            while (sum > x and i > 0) {
                i--;
                sum -= a[i];
            }
            if (sum <= x and i + j > cnt)
                cnt = i + j;
        }
        cout << cnt << "\n";
    }
    return 0;
}
