    #include <bits/stdc++.h>
    using namespace std;
    const int N = 100010;
    typedef long long ll;
    
    void solve() {
        int n, t;
        cin >> n >> t;
        vector<int> w(n + 1);
        for (int i = 1; i <= n; i ++ ) 
            cin >> w[i];
        function<bool(int)> check = [&] (int mid) {
            priority_queue<int, vector<int>, greater<int>> q;
            int maxx = 0;
            for (int i = 1; i <= mid; i ++ ) 
                q.push(w[i]), maxx = max(maxx, w[i]);
            for (int i = mid + 1; i <= n; i ++ ) {
                auto u = q.top();
                q.pop();
                u += w[i];
                maxx = max(u, maxx);
                q.push(u);
            }
            return maxx <= t;
        };
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << "\n";
    }
    
    int main(void) {
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int T = 1;
        while (T -- ) solve();
        system("pause");
        return 0;
    }