#include <iostream>
using namespace std;
const int N = 100010;
int n;

int main(){
	cin>>n;
	for(int i =2 ; i<=n;++i){
		if( n%i == 0){
			int s = 0;
			while( n%i ==0) {
				++s;
				n/=i;
			}
			cout<<i<<"^"<<s<<"   ";
		}
	}
	if( n>1) cout<<n<<endl;
	return 0; 
}
