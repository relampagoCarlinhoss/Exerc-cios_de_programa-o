#include <bits/stdc++.h> 
using namespace std; 

struct Pistas{
	int linha; 
	int coluna;
	int dist;
};

int main(){
	int n, q_pistas; 
	bool tesouro = true; 
	int total_tesouros = 0; 
	int linha = 0, coluna = 0;	
	
	cin >> n >> q_pistas; 

	vector<Pistas> pistas(q_pistas);
	
	for(int i = 0; i < q_pistas; i++){
		cin >> pistas[i].coluna >> pistas[i].linha >> pistas[i].dist;	
	}

	for(int j = 0; j < n; j++){
		for(int i = 0; i < n; i++){
			tesouro = true;
			for(int k = 0; k < q_pistas; k++){
				int dist_real = abs(pistas[k].linha - i) + abs(pistas[k].coluna - j);
				
				if(dist_real != pistas[k].dist){
					tesouro = false; 			
					break;
				}				
			}	

			if(tesouro){
				total_tesouros++;
				linha = i;
				coluna = j; 				
			}
		}	
	}
	
	if(total_tesouros == 1) cout << coluna << " " << linha;	
	else cout << -1 << " " << -1;

return 0;
}
