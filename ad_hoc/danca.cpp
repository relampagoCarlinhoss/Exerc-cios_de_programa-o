#include <bits/stdc++.h>
using namespace std;

int main(){
	int linha, coluna, n_passos;
	cin >> linha >> coluna >> n_passos; 

	vector<int>pos_linha(linha + 1); 
	vector<int>pos_coluna(coluna + 1);
	
	for(int i = 1; i <= linha; i++){pos_linha[i] = i;}
	for(int j = 1; j <= coluna; j++){pos_coluna[j] = j;}

	string passo;
	int a, b; 
	for(int i = 0; i < n_passos; i++){
		cin >> passo >> a >> b;
		if(passo == "L"){
			swap(pos_linha[a], pos_linha[b]);
		}		
		
		if(passo == "C"){
			swap(pos_coluna[a], pos_coluna[b]);	
		}	
	
	}

	for( int i = 1; i  <= linha; i++){
		for(int j = 1; j <= coluna; j++){
			int loc_l = pos_linha[i];	
			int loc_c = pos_coluna[j];
			
		int res = coluna*(loc_l - 1) + loc_c; 
			cout << res << " ";
		}
		cout << "\n";
	}

	return 0;
}
