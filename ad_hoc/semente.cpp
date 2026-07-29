#include <bits/stdc++.h>
using namespace std;

int main(){
	int leng, q_sem, loc;
	cin >> leng >> q_sem;
	vector<int> pos(leng + 1, 0);

	for(int i = 0; i < q_sem; i++){
		cin >> loc; 
		pos[loc] = 1;	
	}

	int q_conq = q_sem; 
	int dia = 0; 
	int rodada = 2; 
	while(q_conq != leng){
		for(int i = 1; i <= leng; i++){
			if(pos[i] == rodada - 1){
				if(i == 1){
					if(pos[2] == 0 ){
						pos[2] = rodada;	
						q_conq++;
					}
				} 		

				else if(i == leng){
					if(pos[i - 1] == 0){
						pos[i - 1] = rodada;	
						q_conq++;
					}	
				}

				else{
					if(pos[i + 1] == 0){
						pos[i + 1] = rodada;	
						q_conq++; 
					}	
					
					if(pos[i - 1] == 0){
						pos[i - 1] = rodada; 	
						q_conq++;
					}					
				}
			}
		}
		rodada++;
		dia++;
	}
		
	cout << dia << "\n";
	return 0; 
}
