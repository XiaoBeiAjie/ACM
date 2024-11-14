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
   
    for (int i = 0; i < tot; i++)  // iС��recv[i]ʱ�Ž�������ֹͬһ��Ԫ�ؽ������Σ��ص���ԭ����λ�á�
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    //�ӵײ����Ϻϲ�
    for (int mid = 1; mid < tot; mid <<= 1) {
   
        //���ϲ����䳤�ȵ�һ�룬�ʼ����������Ϊ1�����кϲ�,mid = 1;
        auto w1 = Complex({
   cos(PI / mid), inv * sin(PI / mid)});
        for (int i = 0; i < tot; i += mid * 2) {
   
            auto wk = Complex({
   1, 0});
            for (int j = 0; j < mid; j++, wk = wk * w1) {
   
                //ֻɨ��벿�֣������任�õ��Ұ벿�ֵĴ�
                auto x = a[i + j], y = wk * a[i + j + mid];
                a[i + j] = x + y, a[i + j + mid] = x - y;
            }
        }
    }
}

int main() {
   
    scanf("%d%d", &n, &m);
    //�������ʽ��ÿһ������ڸ�����ʵ��
    for (int i = 0; i <= n; i++) scanf("%lf", &a[i].x);
    for (int i = 0; i <= m; i++) scanf("%lf", &b[i].x);
    while ((1 << bit) < n + m + 1) bit++;
    tot = 1 << bit;
    for (int i = 0; i < tot; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    // fft ��a��b��ϵ����ʾת��Ϊ��ֵ��ʾ
    fft(a, 1), fft(b, 1);
    //��������ϵ����ʾ���Ķ���ʽ��˺�ĵ�ֵ��ʾ
    for (int i = 0; i < tot; i++) a[i] = a[i] * b[i];
    //��Ӧ����ˣ�O(n)�õ���ֵ��ʾ�Ķ���ʽ�Ľ�C��������任��ɲ�ֵ�õ���C�ĵ�ֵ��ʾ
    fft(a, -1);
    //����� x �� y �� double ��
    for (int i = 0; i <= n + m; i++) printf("%d ", (int)(a[i].x / tot + 0.5));

    return 0;
}

