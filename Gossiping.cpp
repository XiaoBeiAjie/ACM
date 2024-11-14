#include <bits/stdc++.h>
using namespace std;
using d64 = double;

bool mem1;

mutex mtx;

void solve() {
    struct Node {
        d64 val;
        d64 get() {
            lock_guard<mutex> lock(mtx);
            return val;
        }
        void set(d64 value) {
            lock_guard<mutex> lock(mtx);
            val = value;
        }
        void fun(Node &node) {
            d64 val_ = node.get();
            d64 avg = (val + val_) / 2.;
            set(avg);
            node.set(avg);
        }
    };
    constexpr int len = 10, r = 1000;
    string file = "result.csv";
    vector<Node> v(len + 1);
    mt19937_64 rnd(time(NULL));
    uniform_real_distribution<d64> rd(1, 1e5);
    for (int i = 1; i <= len; i ++ ) 
        v[i].set(rd(rnd));
    function<void(int)> work = [&] (int n) {
        vector<thread> t_v;
        for (int i = 1; i <= n; i ++ ) {
            int idx_1 = rnd() % len + 1;
            int idx_2 = rnd() % len + 1;
            while (idx_2 == idx_1) 
                idx_2 = rnd() % len + 1;
            t_v.emplace_back([&] () {
                v[idx_1].fun(v[idx_2]);
            });
        }
        for (auto &t : t_v) 
            if (t.joinable()) t.join();
        t_v.clear();
    };
    ofstream csv_file(file, ios::app);
    mutex file_mtx;
    function<void(int)> export_ = [&] (int n) {
        lock_guard<mutex> lock(file_mtx);
        csv_file << "round: " << n << "\n";
        for (int i = 1; i <= len; i ++ ) 
            csv_file << fixed << setprecision(10) << v[i].get() << " \n"[i == len];
    };  
    for (int i = 1; i <= r; i ++ ) {
        work(1);
        if (!(i % 10)) export_(i);
    }
    csv_file.close();
}

bool mem2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    cerr << fixed << setprecision(2) << "Memory : " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB\n";
    #endif
    int T = 1;
    while (T -- ) solve();
    #ifdef LOCAL
    cerr << "Time : " << clock() * 1000 / CLOCKS_PER_SEC << "MS\n";
    #endif
    return 0;
}