#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> permutas(6);
	for(int i = 0; i < 6; i++){cin >> permutas[i];}	
	sort(permutas.begin(), permutas.end());

	do{
			if((permutas[0] + permutas[1] + permutas[2] == permutas[3] + permutas[4]) && (permutas[4]  + permutas[3] == permutas[5])){
				cout << "S";
				return 0; 	
			}	
	} while(next_permutation(permutas.begin(),permutas.end()));
	
	cout << "N";	
	return 0;
}
