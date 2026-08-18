#include <bits/stdc++.h>
using namespace std; 

int main(){
	int q_grupos; 
	int taxi = 0; 
	cin >> q_grupos; 

	vector<int> grupos(q_grupos); 
	for(int i = 0; i < q_grupos; i++){
		cin >> grupos[i];	
	}
	sort(grupos.begin(), grupos.end());
	int i = 0; 
	int j = grupos.size() - 1; 
	while(i <= j){
		if(grupos[j] == 4){
			j--;		
			taxi++;
		}	

		if(grupos[j] == 3){
			if(grupos[i] == 1){
				i++;
				j--; 
				taxi++;	
			}	
			
			else{
				j--;
				taxi++;	
			}
		}

		if(grupos[j] == 2){
			if(grupos[i] == 1 && grupos[i + 1] == 1){
				i += 2; 	
				j--; 
				taxi++; 
			}	

			else if(grupos[i] == 2){
				i++;
				j--;
				taxi++;	
			}

			else if(grupos[i] == 1){
				i++;
				j--;
				taxi++;			
			}
			
			else{
				j--;
				taxi++;	
			}
		}

		if(grupos[j] == 1){
			int qtd_res = j - i + 1;
			taxi += (qtd_res + 3)/4;
			break;
		}
	}

	cout << taxi;

	return 0; 
}
