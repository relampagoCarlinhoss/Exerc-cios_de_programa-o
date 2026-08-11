#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; 
	cin >> n; 

	for(int i = 0; i < (1 << n); i++){
		vector<int> subset;
		for(int j = 0; j < n; j++){
			//o j funciona como uma lupa que quando comparada com a expansao binaria do elemento, revela se ele deve estar presente ou nao, 
			if(i & (1 << j)) subset.push_back(j);
		}
		for(int k:subset){cout << k << " ";}
		cout << "\n";
	}
	return 0;
}
