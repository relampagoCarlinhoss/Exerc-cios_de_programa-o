#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>brl(n + 1);

	for(int i = 0; i < n; i++){
		int carta; 
		cin >> carta;
		brl[carta] = i;	
	}

		int run = 1;
	
	int last = brl[1];
	for(int i = 2; i <= n; i++){
		if(last > brl[i]){
			run++;
		}	
		last = brl[i];
	}	
	
	int res = ceil(log2(run));
	
	cout << res; 

	return 0;
}
