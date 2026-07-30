#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 0;
	vector<int> subset;
	cin >> n;

	for(int b = 0; b < (1 << n); b++){
		for(int i = 0; i < n; i++){
			if(i == 0){cout << "{";}
			if(b&(1 << i)){
				cout << i << ",";				
			}	
			if(i == n - 1){cout << "}";}
		}	
	
	}

	return 0; 
}
