#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> vec_str;
map<string, int> mp_id, mp_key;
int cnt, cur;

int get_id(string s) {
    if (mp_id.find(s) != mp_id.end())
        return mp_id[s];
    vec_str.push_back(s);
    return mp_id[s] = cnt ++;
}

struct Line {
    int create_time, delete_time;
    vector<int> cons;
    Line (int create_time = 0, vector<int> cons = {}) : create_time(create_time), cons(cons) {
        delete_time = -1;
    }
    Line (int create_time, vector<string> cons) : create_time(create_time) {
        delete_time = -1;
        for (auto s : cons) {
            this->cons.push_back(get_id(s));
        }
    }
    void set_delete_time (int delete_time) {
        this->delete_time = delete_time;
    }
    bool valid (int time) {
        return ~create_time && create_time <= time && !~delete_time;
    }
};

struct Date {
    vector<Line> line;
    int tot, update_time;
    Date () {
        tot = 0, update_time = 0;
    }
    void insert (int time, vector<string> & cons) {
        tot ++;
        line.push_back(Line(time, cons));
    }
    int del (int time, string & s_key, vector<int> s) {
        int del_cnt = 0, key = mp_key[s_key];
        set<int> vis;
        for (auto u : s) 
            vis.insert(u);
        for (auto &cline : line) {
            if (cline.valid(time) && vis.find(cline.cons[key]) != vis.end()) {
                cline.set_delete_time(time);
                del_cnt ++;
            }
        }
        return del_cnt;    
    }
    void commit () {}
    void abort () {
        for (auto & cline : line) {
            if (update_time <= cline.create_time) 
                cline.create_time = -1;
            if (update_time <= cline.delete_time)
                cline.delete_time = -1;
        }
    }
    void  set_update_time(int time) {
        this->update_time = time;
    }
    vector<int> select (int time, string & s_key1, string & s_key2, vector<int> s) {
        int key1 = mp_key[s_key1], key2 = mp_key[s_key2];
        set<int> vis;
        for (auto u : s) 
            vis.insert(u);
        vector<int> ans;
        for (auto & cline : line) {
            if (cline.valid(time) && vis.find(cline.cons[key2]) != vis.end())
                ans.push_back(cline.cons[key1]);
        }
        return ans;
    }
};


#define ABORT 1
#define BEGIN 2
#define COMMIT 3
#define SELECT 4
#define SELECT_IN 5
#define INSERT 6
#define DELETE 7
#define DELETE_IN 8

//enum Type {ABORT, BEGIN, COMMIT, SELECT, SELECT_IN, INSERT, DELETE, DELETE_IN};

void solve() {
    map<string, int> mp_type;
    function<void()> init = [&] () {
        mp_type["abort"] = 1;
        mp_type["begin"] = 2;
        mp_type["commit"] = 3;
        mp_type["select"] = 4;
        mp_type["select_in"] = 5;
        mp_type["insert"] = 6;
        mp_type["delete"] = 7;
        mp_type["delete_in"] = 8;

    };
    init();
    int n, m;
    cin >> n >> m;
    vector<string> key(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> key[i];
        mp_key[key[i]] = i;
    }
    Date date;
    function<vector<int>(string)> explain = [&] (string op) {
        int idx = op.find('(');
        if (idx == op.npos) return vector<int>{get_id(op)};
        function<int()> get_next = [&] () {
            return op.find(',', idx + 1);
        };
        int type = mp_type[op.substr(0, idx)];
        vector<string> val;
        vector<int> ans;
        switch (type) {
            case ABORT:
                date.abort();
                break;
            
            case BEGIN:
                date.set_update_time(cur);
                break;

            case COMMIT:
                date.commit();
                break;

            case SELECT:
            case SELECT_IN:
                for (int i = 0; i < 2; i ++ ) {
                    int nxt = get_next();
                    val.push_back(op.substr(idx + 1, nxt - idx - 1));
                    idx = nxt;
                }
                val.push_back(op.substr(idx + 1, op.size() - idx - 2));
                return date.select(cur, val[0], val[1], explain(val[2]));
                break;

            case INSERT:
                for (int i = 0; i < n - 1; i ++ ) {
                    int nxt = get_next();
                    val.push_back(op.substr(idx + 1, nxt - idx - 1));
                    idx = nxt;
                }
                val.push_back(op.substr(idx + 1, op.size() - idx - 2));
                date.insert(cur, val);
                break;

            case DELETE:
            case DELETE_IN:
                int nxt = get_next();
                val.push_back(op.substr(idx + 1, nxt - idx - 1));
                idx = nxt;
                val.push_back(op.substr(idx + 1, op.size() - idx - 2));
                cout << date.del(cur, val[0], explain(val[1])) << "\n";
                break;
        }
        return vector<int>{};
    };
    for (int i = 1; i <= m; i ++ ) {
        string op; cin >> op;
        cur ++;
        auto ans = explain(op);
        if (op[0] == 's') {
            cout << ans.size() << "\n";
            if (ans.size())
                cout << vec_str[ans[0]] << "\n" << vec_str[ans[(ans.size() - 1) >> 1]] << "\n" << vec_str[ans.back()] << "\n";
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}