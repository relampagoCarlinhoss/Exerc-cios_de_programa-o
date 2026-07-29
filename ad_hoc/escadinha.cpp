#include <bits/stdc++.h>
using namespace std; 

int main(){
	int q_nmr;
	cin >> q_nmr; 

	int nmr_1, nmr_2;
	int escadinha = 1;	
	int diff_old = 0; 

	cin >> nmr_1; 	
	for(int i = 0; i < q_nmr - 1; i++){ 
		nmr_2 = nmr_1;
		cin >> nmr_1;		
		
		if(i == 0){
			diff_old = abs(nmr_1 - nmr_2);	
		}

		int diff_new = abs(nmr_1 - nmr_2);
		
		if(diff_new != diff_old){
			escadinha++;	
			diff_old = diff_new; 
		}
	}
	
	cout << escadinha;
	return 0;
}
