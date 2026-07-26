#include <bits/stdc++.h>
using namespace std;

int main(){	
	int leng;
	cin >> leng;	
	
	char tab[leng][leng];	
	for(int i = 0; i < leng; i++){
		for(int j = 0; j < leng; j++){
			cin >> tab[i][j];	
		}	
	}

	int comida = 0;	
	int lim = leng, j = 0;
	bool condicao;
	int comida_final = 0; 
	int recorde = 0;
	for(int i = 0; i < leng; i++){
		bool etapa = (i % 2 == 0);
		if(etapa){
			j = 0;
			lim = leng;
			condicao = (j < lim);
		}

		else{
			j = leng - 1; 
			lim = 0;	
			condicao = (j >= lim);
		}

		while(condicao){	
			if(tab[i][j] == 'o'){
				comida++;	
			}		

			if(tab[i][j] == 'A'){
				recorde = (comida > recorde) ? comida: recorde;	
				comida = 0; 	
			}	
			
			if(i == leng - 1 && (j >= leng - 1 || j == 0)){
				comida_final = comida; 			
			}

			if(etapa){
				j++;	
				condicao  = j < lim;
			}

			else{
				j--;	
				condicao = j >= lim;
			}
		} 
	}

	int pont_final = comida_final > recorde ? comida_final : recorde;  
	cout << pont_final; 

	return 0;
}
