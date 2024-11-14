#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int  N = 2010,mod = 1e9 + 7;

//   C a b  =  C  (a-1) b + C  a-1   b-1
//  ��һ��     10w ������     1<=a,b<=2000     ���� 
int c[N][N];
void init()
{
	for(int i = 0; i< N ; ++i){
		for(int j = 0 ; j<=i ; ++j){
			if( j==0) c[i][j] = 1;
			else c[i][j] = ( c[i-1][j-1]+ c[i-1][j]) % mod;
		}
	}
}

//�ڶ��ַ���   1��������  1<=a,b<=10^5     Ԥ����   
// C a b =  feet(a) * infeet(b-a)* infeet(a)
// fact  = a! % mod , if a/b = i mod m, call x = b^(-1)  . b^(-1)  = infact(a) 
const int N1 = 100010;
long long fact[N1],infact[N1]; // ����Ϊ��Ԫ 
long long qmi( int a,int k , int p){
	long long res = 1;
	while( k){
		if( k & 1 ) res  = res* a %p;
		k>>=1;
		a =  (long long )a*a %p; 
	}
	return res;
}

int  C2( int a,int b){
	fact[0] = infact[0] = 1;
	for(int i = 1; i< N1 ;++i){
		fact[i] = (long long ) fact[i-1]*i %mod;
		//�����infactҪ�� modΪ���� ���ܼ������� 
		infact[i] = (long long ) infact[i-1] * qmi( i , mod-2,mod) %mod; 
	}
	return fact[a]*infact[a-b]%mod *infact[b] %mod;
}


//�����ּ��㷽��   20������    1<=a,b<= 10^18   , 1<=p <= 10^5   
//¬��˹����    C a b =  C   a mod p    b mod p  *  C a/p  b/p   mod p  

int C(int a,int b){
	return C2(a,b);
}

int lucas(int a, int b,int p ){
	if( a< p && b< p) return C(a,b);
	return (long long ) C( a%p , b%p ) * lucas( a/p , b/p,p) %p ;
}

//�����ּ��㷽��  Ҫ��߾���������
// a = [n/p] + [n / p^2] + ...
const int N3 = 5010;
int primes[N3], cnt;
bool st[N3];
int sum[N3];

void  get_primes( int x){
	for(int i = 2; i<=x ;++i){
		if( !st[i]) primes[cnt++] = i;
		for(int j = 0 ; j<cnt && primes[j] <= x/i; ++j){
			st[i * primes[j]] = true;
			if( i% primes[j] == 0) break;
		}
	}
}
 
//get ���n�У� p�ĸ��� 
int get( int n , int p) {
	int res = 0;
	while( n){
		res+= n/p;
		n/=p;
	}
	return res;
}

vector<int> mul( vector<int> a , int b){
	vector<int> c;
	int t= 0;
	for(int i = 0 ; i<a.size() ; ++i){
		t+= a[i]*b;
		c.push_back( t%10);
		t/=10; 
	}
	while(t){
		c.push_back( t%10);
		t/=10;
	}
	return c;
}

 
int C4(int a, int b,int p){
	
	get_primes(a);
	for(int i = 0 ; i< cnt ; ++i){
		int p = primes[i];
		sum[i]  = get(a,p) - get(b,p) -get(a-b,p);
	}
	vector<int > res;
	res.push_back(1);
	for(int i =0 ;i< cnt ; ++i){
		for(int j = 0 ; j<sum[i] ; ++j){
			res = mul( res, primes[i]);
		}
	}
	for(int i = res.size()-1 ; i>=0 ; --i ) cout<<res[i];
	return 0;
} 
 


int main() 
{

	int a,b;
	cin>>a>>b;
	C4(a,b,mod);
	return 0;
 } 
