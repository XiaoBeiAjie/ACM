#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int > res;
	for(int i = 1; i<= n/i ; ++i){
		if( n%i == 0){
			res.push_back(i);
			if( i != n/i) res.push_back(n/i);
		}
	}
	for(int i = 0 ; i< res.size() ; ++i){
		cout<<res[i]<<" ";
	}
	return 0;
}
