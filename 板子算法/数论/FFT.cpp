#include <bits/stdc++.h>

using namespace std;

const int N = 3e6;
const double PI = acos(-1);

int n, m;
struct Complex {
   
    double x, y;
    Complex operator+(const Complex& t) const {
    return {
   x + t.x, y + t.y}; }
    Complex operator-(const Complex& t) const {
    return {
   x - t.x, y - t.y}; }
    Complex operator*(const Complex& t) const {
   
        return {
   x * t.x - y * t.y, x * t.y + y * t.x};
    }
} a[N], b[N];
int rev[N], bit, tot;

void fft(Complex a[], int inv) {
   
    for (int i = 0; i < tot; i++)  // i小于recv[i]时才交换，防止同一个元素交换两次，回到它原来的位置。
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    //从底层往上合并
    for (int mid = 1; mid < tot; mid <<= 1) {
   
        //待合并区间长度的一半，最开始是两个长度为1的序列合并,mid = 1;
        auto w1 = Complex({
   cos(PI / mid), inv * sin(PI / mid)});
        for (int i = 0; i < tot; i += mid * 2) {
   
            auto wk = Complex({
   1, 0});
            for (int j = 0; j < mid; j++, wk = wk * w1) {
   
                //只扫左半部分，蝴蝶变换得到右半部分的答案
                auto x = a[i + j], y = wk * a[i + j + mid];
                a[i + j] = x + y, a[i + j + mid] = x - y;
            }
        }
    }
}

int main() {
   
    scanf("%d%d", &n, &m);
    //读入多项式的每一项，保存在复数的实部
    for (int i = 0; i <= n; i++) scanf("%lf", &a[i].x);
    for (int i = 0; i <= m; i++) scanf("%lf", &b[i].x);
    while ((1 << bit) < n + m + 1) bit++;
    tot = 1 << bit;
    for (int i = 0; i < tot; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    // fft 把a、b的系数表示转化为点值表示
    fft(a, 1), fft(b, 1);
    //计算两个系数表示法的多项式相乘后的点值表示
    for (int i = 0; i < tot; i++) a[i] = a[i] * b[i];
    //对应项相乘，O(n)得到点值表示的多项式的解C，利用逆变换完成插值得到答案C的点值表示
    fft(a, -1);
    //这里的 x 和 y 是 double 的
    for (int i = 0; i <= n + m; i++) printf("%d ", (int)(a[i].x / tot + 0.5));

    return 0;
}

