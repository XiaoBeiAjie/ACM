#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010, mod = 1000000007;
typedef long long LL;

class matrix {
public:
    matrix() {
    }
 
    matrix(int n, int m) {
        v.resize(n, vector<int>(m, 0));
    }
 
    int rows() const {
        return v.size();
    }
 
    int columns() const {
        if (v.size()) {
            return v[0].size();
        }
        return 0;
    }
 
    matrix transpose() const {
        matrix res(columns(), rows());
        for (int i = 0; i < rows(); ++i) {
            for (int j = 0; j < columns(); ++j) {
                res[j][i] = v[i][j];
            }
        }
        return res;
    }
 
    matrix operator + (const matrix &m) const {
        matrix res(rows(), columns());
        for (int i = 0; i < rows(); ++i) {
            for (int j = 0; j < columns(); ++j) {
                res[i][j] = v[i][j] + m[i][j];
                if (res[i][j] >= mod) {
                    res[i][j] -= mod;
                }
            }
        }
        return res;
    }
 
    matrix operator * (const matrix &m) const {
        matrix res(rows(), m.columns());
        matrix t = m.transpose();
        for (int i = 0; i < res.rows(); ++i) {
            for (int j = 0; j < res.columns(); ++j) {
                auto first = v[i].begin();
                auto second = t[j].begin();
                unsigned long long sum = 0;
                int it = 0;
                for (int k = 0; k < v[i].size(); ++k) {
                    sum += 1LLU * (*first) * (*second);
                    ++first;
                    ++second;
                    ++it;
                    if (it == 17) {
                        sum %= mod;
                        it = 0;
                    }
                }
                res[i][j] = sum % mod;
            }
        }
        return res;
    }
 
    vector<int>& operator [] (int row) {
        return v[row];
    }
 
    const vector<int>& operator [] (int row) const {
        return v[row];
    }
 
    bool operator == (const matrix &m) const {
        if (rows() == m.rows() && columns() == m.columns()) {
            for (int i = 0; i < rows(); ++i) {
                for (int j = 0; j < columns(); ++j) {
                    if (v[i][j] != m[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        }
        return false;
    }
 
    friend ostream &operator << (ostream &os, const matrix &m) {
        for (int i = 0; i < m.rows(); ++i) {
            for (int j = 0; j < m.columns(); ++j) {
                os << m[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
 
private:
    vector<vector<int>> v;
};
 
matrix one(int n) {
    matrix res(n, n);
    for (int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }
    return res;
}
 
matrix power(const matrix &a, long long b) {
    if (b == 0) {
        return one(a.rows());
    }
    if (b % 2 == 0) {
        return power(a * a, b / 2);
    }
    return a * power(a, b - 1);
}

void solve() {
    int n, m;
    cin >> m >> n;
    vector<int> t(m), l(m);
    for (int i = 0; i < m; i ++ ) cin >> t[i];
    for (int i = 0; i < m; i ++ ) cin >> l[i], t[i] += l[i];
    matrix A(m, m);
    for (int i = 0; i < m; i ++ ) 
        for (int j = 0; j < m; j ++ ) 
            A[i][j] = (t[i] * t[j] - l[i] * l[j] + mod) % mod;
    A = power(A, n);
    LL ans = 0;
    for (int i = 0; i < m; i ++ ) 
        ans = (ans + A[0][i]) % mod;
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}