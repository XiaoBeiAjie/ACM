#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL ; 
const LL mod = 1e9+7 ; 
class Matrix {
public :
  vector< vector<LL>> m ; 
  int size;
  Matrix() {size = 0;}
  Matrix( int _size ,LL val) :size(_size) , m( _size+1, vector<LL>(_size+1 ,0 )) {
  		if( val == 1 ) for(int i=1; i <=size ; ++ i ) m[i][i] = 1 ;
	}
  Matrix operator*(Matrix& rhs) {
    Matrix t(size, 0);
    int n =size;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= n; ++k) {
          t.m[i][j] += (m[i][k] * rhs.m[k][j] %mod) ; 
          t.m[i][j] %= mod ;
        }
      }
    }
    return t;
  }

};

Matrix qmi(Matrix x, LL n) {
  Matrix ans(x.size,1);
  while (n) {
    if (n & 1) {
      ans = ans * x;
    }
    x = x * x;
    n >>= 1;
  }
  return ans;
}

int main(){

    int T; cin >>T ;
    while( T--) {
    	Matrix mt( 3 , 0 )  ;
		mt.m[1][1] = mt.m[1][3] = mt.m[2][1] = mt.m[3][2] = 1 ;
    	int n ; cin >> n  ;
	    if( n >3 ) {
	    	mt = qmi(mt, n -1);
	    	cout << mt.m[1][1] <<'\n' ; 
		}else {
			cout << 1 <<'\n' ; 
		}
	}

	return  0 ; 
}

