#include <bits/stdc++.h> 
using namespace std;

int new_comb(vector<int>torre, int comb, int linha){
	int a = linha*6;
	int b = linha*6 + 1; 
	int c = linha*6 + 2;
	int d = linha*6 + 3;
	int e = linha*6 + 4;
	int f = linha*6 + 5;

	for(int i = linha*6; i < (linha + 1)*6; i++){
		if(torre[i] == comb){
			if(i == a){return torre[f];}			
			if(i == b){return torre[d];}
			if(i == c){return torre[e];}
			if(i == d){return torre[b];}
			if(i == e){return torre[c];}
			if(i == f){return torre[a];}
		}	
	}

	return 0; 
}

int achar_caminho(vector<int> &torre, int linha, int n, int comb){	
	if(linha == n) {
		return 0; 
	}

	int proximo_comb = new_comb(torre, comb, linha);
	int melhor = -1;
	for(int i = 6; i >= 1; i--){
		if(i != comb && i != proximo_comb){
			int ant = achar_caminho(torre, linha + 1, n, i);
			melhor = max(melhor, i + ant);
		}
	}
	return melhor; 
}

int main(){
	int leng;
	int soma = 0; 
	cin >> leng; 

	vector<int> torre(leng*6);
	for(int i = 0; i < torre.size(); i++){cin >> torre[i];}
	
	int maior_soma = 0;

	for(int i = 0; i < 6; i++){
		int comb_inicial = torre[i];
		maior_soma = max(maior_soma,achar_caminho(torre, 0, leng, comb_inicial));

	}

	cout << maior_soma << "\n";
	return 0;
}
