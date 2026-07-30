#include <bits/stdc++.h>
using namespace std; 

void n_rainha(vector<bool> &colun, vector<bool> &diag1, vector<bool> &diag2,int y, int n,int q_rainha, int &solucoes){
	if(q_rainha == n){
		solucoes++;	
	}	

	for(int x = 0; x < n; x++){
		if(colun[x] || diag1[x + y] || diag2[x - y + n - 1]){continue;}	
		colun[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
		n_rainha(colun, diag1, diag2, y + 1, n, q_rainha + 1, solucoes);	
		colun[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
	} 
}

int main(){
	int n;
	int solucoes = 0;
	int y = 0; 
	int q = 0;
	cin >> n;

	vector<bool> coluna(n);
	vector<bool> d1(2*n - 1);
	vector<bool> d2(2*n - 1);
	
	n_rainha(coluna, d1, d2, y, n, q,solucoes);	
	
	cout << solucoes;


	return 0;
}
