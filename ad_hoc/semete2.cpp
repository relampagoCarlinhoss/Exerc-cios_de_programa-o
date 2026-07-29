#include <bits/stdc++.h>
using namespace std;

int main(){
	int leng, q_sem, loc;
	cin >> leng >> q_sem;

	vector<int> pos(leng + 1, 0);
	vector<int> ind(q_sem);
	for(int i = 0; i < q_sem; i++){
		cin >> loc; 
		pos[loc] = 1;	
		ind[i] = loc; 	
	}

	int q_conq = q_sem; 
	int dia = 0; 
	int rodada = 1; 
	while(q_conq != leng){
		for(int i = 0; i < q_sem; i++){

			int gar_d = ind[i] + rodada; 
			if(gar_d <= leng && pos[gar_d] == 0){		
				pos[gar_d] = 1; 	
				q_conq++;	
			}	

			int gar_e = ind[i] - rodada; 
			if(gar_e >= 1 && pos[gar_e] == 0){
				pos[gar_e] = 1; 
				q_conq++; 	
			}
		}
		dia++;
		rodada++;
	}
		
	cout << dia << "\n";
	return 0; 
}
