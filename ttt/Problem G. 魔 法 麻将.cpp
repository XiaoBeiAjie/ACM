    #include <bits/stdc++.h>
    using namespace std;
    using i64 = long long;

    void solve() {
        string s; cin >> s;
        map<string, int> mp;
        {
            mp["1z"] = 1;
            mp["2z"] = 2;
            mp["3z"] = 3;
            mp["4z"] = 4;
            mp["5z"] = 5;
            mp["6z"] = 6;
            mp["7z"] = 7;
            mp["1s"] = 8;
            mp["9s"] = 9;
            mp["1p"] = 10;
            mp["9p"] = 11;
            mp["1m"] = 12;
            mp["9m"] = 13;
        }
        function<bool()> check_1 = [&] () {
            vector<int> cnt(14);
            for (int i = 0; i < s.size(); i += 2) {
                string t = "";
                t += s[i], t += s[i + 1];
                if (mp.find(t) == mp.end()) return false;
                cnt[mp[t]] ++;
            }
            for (int i = 8; i <= 13; i ++ ) 
                if (!cnt[i]) return false;
            return true;
        };
        function<bool()> check_2 = [&] () {
            unordered_map<string, int> cnt;
            for (int i = 0; i < s.size(); i += 2) {
                string t = "";
                t += s[i], t += s[i + 1];
                cnt[t] ++;
            }
            for (auto [u, c] : cnt) 
                if (c != 2) return false;
            return true;
        };
        if (check_1()) return cout << "Thirteen Orphans\n", void();
        else if (check_2()) return cout << "7 Pairs\n", void();
        return cout << "Otherwise\n", void();
    }

    int main(void) {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int T; cin >> T;
        while (T -- ) solve();
        return 0;
    }