#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

// TODO: Dynamic ModInt

template<typename T>
constexpr T power(T a, u64 b) {
    T res {1};
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}

template<u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
    return 1ULL * a * b % P;
}

template<u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

template<typename U, U P>
requires std::unsigned_integral<U>
struct ModIntBase {
public:
    constexpr ModIntBase() : x {0} {}
    
    template<typename T>
    requires std::integral<T>
    constexpr ModIntBase(T x_) : x {norm(x_ % T {P})} {}
    
    constexpr static U norm(U x) {
        if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }
    
    constexpr U val() const {
        return x;
    }
    
    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = norm(P - x);
        return res;
    }
    
    constexpr ModIntBase inv() const {
        return power(*this, P - 2);
    }
    
    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<P>(x, rhs.val());
        return *this;
    }
    
    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    
    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    
    constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
        return *this *= rhs.inv();
    }
    
    friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {
        lhs *= rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase &rhs) {
        lhs += rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase &rhs) {
        lhs -= rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {
        lhs /= rhs;
        return lhs;
    }
    
    friend constexpr std::ostream &operator<<(std::ostream &os, const ModIntBase &a) {
        return os << a.val();
    }
    
    friend constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() == rhs.val();
    }
    
    friend constexpr bool operator!=(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() != rhs.val();
    }
    
    friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() < rhs.val();
    }
    
private:
    U x;
};

template<u32 P>
using ModInt = ModIntBase<u32, P>;

template<u64 P>
using ModInt64 = ModIntBase<u64, P>;

constexpr u32 P = 1000000007;
using Z = ModInt<P>;

void solve() {
    int n, m, K, hp;
    cin >> n >> m >> K >> hp;
    vector<string> s(n);
    for (int i = 0; i < n; i ++ ) 
        cin >> s[i];
    int px = -1, py = -1, ex = -1, ey = -1;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (s[i][j] == 'P')
                px = i, py = j;
            else if (s[i][j] == 'E')
                ex = i, ey = j;
    vector dp(n, vector<Z> (n));
    for (int x = 0; x < n; x ++ ) 
        for (int y = 0; y < n; y ++ ) 
            if (s[x][y] != '#') 
                dp[x][y] = 1;
    constexpr int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    function<bool(int, int)> valid = [&] (int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < n && s[x][y] != '#');
    };
    for (int i = 0; i < K; i ++ ) {
        vector ndp(n, vector<Z> (n));
        for (int x = 0; x < n; x ++ )
            for (int y = 0; y < n; y ++ ) {
                if (dp[x][y] == 0) continue;
                for (int k = 0; k < 4; k ++ ) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (valid(nx, ny))
                        ndp[nx][ny] += dp[x][y];
                }
            }
        dp = move(ndp);
    }
    Z ans = 0;
    vector f(n, vector (n, array<array<array<Z, 9>, 9>, 5> ()));
    f[px][py][0][4][4] = 1;
    for (int i = 0; i < m - K; i ++ ) {
        vector g(n, vector (n, array<array<array<Z, 9>, 9>, 5> ()));
        for (int x = 0; x < n; x ++ )
            for (int y = 0; y < n; y ++ )
                for (int d = 0; d < hp; d ++ )
                    for (int edx = -d; edx <= d; edx ++ )
                        for (int edy = -d; edy <= d; edy ++ ) {
                            Z res = f[x][y][d][edx + 4][edy + 4];
                            if (res == 0)
                                continue;
                            for (int k = 0; k < 4; k ++ ) {
                                int nx = x + dx[k], ny = y + dy[k];
                                if (!valid(nx, ny)) 
                                    continue;
                                int nd = d, nedx = edx, nedy = edy;
                                int nex = nx - px + ex + edx;
                                int ney = ny - py + ey + edy;
                                if (!valid(nex, ney)) {
                                    nd ++;
                                    if (nd >= hp) {
                                        //cerr << nex << " " << ney << "\n";
                                        ans += res * dp[nx][ny];
                                        continue;
                                    }
                                    nedx -= dx[k], nedy -= dy[k];
                                }
                                g[nx][ny][nd][nedx + 4][nedy + 4] += res;
                            }
                        }
        f = move(g);                   
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}