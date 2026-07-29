using namespace std;
#include <bits/stdc++.h> 

int main(){
	vector<int>d_foto(2);
	int q_fotos;
	cin >> d_foto[0] >> d_foto[1] >> q_fotos;
	int area_foto = d_foto[0]*d_foto[1];

	vector<int>d_moldura(2);
	int escolha = -1;
	int s1 = 0;

	for(int i = 1; i <= q_fotos; i++){
		cin >> d_moldura[0] >> d_moldura[1];
		int s2 = min(d_moldura[0], d_moldura[1]) - min(d_foto[0], d_foto[1]); 
		int s3 = max(d_moldura[0], d_moldura[1]) - max(d_foto[0], d_foto[1]);	
		
		if(s2 < 0 || s3 < 0 ) continue; 

		int sobra = d_moldura[0]*d_moldura[1] - area_foto;
		if(sobra< s1 || escolha == -1){
			escolha = i;
			s1 = sobra;
		} 
	}
	
	cout << escolha;
	return 0;
}
