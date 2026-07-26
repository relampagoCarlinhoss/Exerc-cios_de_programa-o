#include <iostream> 
using namespace std;

bool verifica_fora(int inicio, int add){
	if(inicio + add - 1 > 10){
		return true; 	
	}
	return false;
}

bool verifica_interseccao(int inicio, int fim, bool ocul[]){
	for(int i = inicio; i <= fim; i++){
		if(ocul[i] != 0){
			return true;
		}	
	}	
	return false; 
}

void adiciona_malha(int inicio, int fim, bool ocul[]){
	for(int i = inicio; i <= fim; i++){
		ocul[i] = 1;	
	}	
}

int main(){
	int q_navio;
	int direc, inc, linha, coluna; 
	bool ocul[100] = {0};

	cin >> q_navio;	
	for(int i = 0; i < q_navio; i++){
		cin >> direc >> inc >> linha >> coluna;
		int inicio = 10*(linha - 1) + coluna;
		int fim = inicio + (inc - 1);

		if(direc == 0){
			if(verifica_fora(coluna, inc)){
				cout << "N";
				return 0;	
			}

			else if(verifica_interseccao(inicio, fim, ocul)){
				cout << "N";
				return 0;	
			} 

			else{
				adiciona_malha(inicio, fim, ocul);
			}
		}

		else{
			if(verifica_fora(linha, inc)){
				cout << "N";	
				return 0;
			} 
			
			else if(verifica_interseccao(inicio, fim,ocul)){
				cout << "N";
				return 0;	
			}

			else{
				adiciona_malha(inicio, fim, ocul);	
			}
		}
	}
	cout << "Y";
	return 0;
}
