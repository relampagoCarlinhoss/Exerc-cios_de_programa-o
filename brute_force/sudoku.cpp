#include<bits/stdc++.h>
using namespace std;
bool valido(vector<int> &matriz){
		for(int i = 0; i < 9; i++){
			vector<int> linha_rep(10, 0);
			for(int j = 0;  j < 9; j++){
				int val = matriz[i*9 + j];
				if(val == 0) continue; 
				if(linha_rep[val] == 1) return false;
				linha_rep[val]++;	
			}	
		}

		for(int i = 0; i < 9; i++){
			vector<int> coluna_rep(10, 0);	
			for(int j = 0; j < 9; j++){
				int val = matriz[j*9 + j];
				if(val == 0) continue; 
				if(coluna_rep[val] == 1) return false;
				coluna_rep[val]++;	
			}
		}

		for(int tri_linha = 0; tri_linha < 9; tri_linha += 3){
			for(int tri_coluna = 0 ; tri_coluna < 9; tri_coluna += 3){
				vector<int> tri_rep(10,0);
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						int val = matriz[(tri_linha+i)*9 + tri_coluna + j];	
						if(val == 0)continue;
						if(tri_rep[val] == 1) return false; 
						tri_rep[val]++;
					}	
				}
			}
		}

	return true;
}

bool sudoku(vector<int> &matriz, int linha, int coluna){
	vector<bool> usado(10);
	set<int> id;
	bool tem_prox = false;

	for(int linha_o = 0; linha_o < 9; linha_o++){
		int val = matriz[linha_o*9 + coluna];
		if(val != 0) usado[val] = true; 
	}		

	for(int coluna_o = 0; coluna_o < 9; coluna_o++){
		int val = matriz[linha*9 + coluna_o];
		if(val != 0) usado[val] = true;
	}
	
	int linha_q = (linha/3)*3;
	int coluna_q =(coluna/3)*3;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int r = linha_q +i;
			int c = coluna_q + j;
			if(matriz[r*9 + c] != 0){usado[matriz[r*9 + c]] = true;}				
		}	
	}
	
	for(int i = 1; i < 10; i++){
		if(!usado[i]){
			id.insert(i);
		}	
	}	

	if(id.empty()){
		return false;	
	}
	
	int proxima_linha, proxima_coluna;
	for(int i = linha*9 + coluna + 1; i < 81; i++){
 		if(matriz[i] == 0){
			proxima_linha = i / 9;
			proxima_coluna = i % 9;	
			tem_prox = true; 
			break;
		}	
	}	

		for(int x : id){
			matriz[linha*9 + coluna] = x; 		

			if(!tem_prox){return true;} 

			if(sudoku(matriz, proxima_linha, proxima_coluna)){
				return true;	
			}
			
			matriz[linha*9 + coluna] = 0;
		}

		return false;	
}

int main(){
	vector<int>  matriz(81, 0);
	
	bool e_sol = true;
	
	for(int i = 0; i < 81; i++){cin >> matriz[i];}
	
	if(!valido(matriz)){
		cout << "NO SOLUTION";
		return 0;	
	}

	for(int i = 0; i < 81; i++){
		if(matriz[i] == 0){
			int linha = i/9;
			int coluna = i%9;
			e_sol = sudoku(matriz,linha, coluna);	
			break;
		}	
	}

	if(e_sol == true){
		for(int i = 0; i < 9; i++){
			if(i != 0){cout << "\n";}
			for(int j = 0; j < 9; j++){
				cout << matriz[i*9 + j] << " ";	
			}	
		}	
	}
	else{
		cout << "NO SOLUTION";	
	}
	return 0; 
}
