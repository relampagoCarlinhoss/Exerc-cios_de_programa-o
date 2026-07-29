#include <bits/stdc++.h> 
using namespace std;

int main(){
	int n_max, q_bola; 

	while(cin >> n_max >> q_bola){
		if(n_max == 0 && q_bola == 0) break;

		vector<bool>cart(n_max + 1, 0);
		vector<int> falta;
		int bola = 0;
		int q_faltas = 0;
		bool coringa = false;		

		for(int i = 0; i < q_bola; i++){
			cin >> bola;
			cart[bola] = 1;			
		}	
		
		for(int i = 0; i < n_max + 1; i++){
			if(cart[i] == 0){
				if(i == 0){
					cout << "N" << "\n";
					coringa = true; 				
					break;
				}
				q_faltas++;
				falta.push_back(i);	
			}	
		}

		if(coringa) continue; 	

		int cont = q_faltas; 
		for(int i = 0; i < cont; i++){
			for(int j = 0; j < (n_max +1) - falta[i]; j++){
				if(cart[j] == 1 && cart[j + falta[i]] == 1){
				       q_faltas--; 	
					break;
				}
			}	
		}

		cout << (q_faltas == 0 ? "Y": "N") << "\n";
	}

	return 0; 
}
