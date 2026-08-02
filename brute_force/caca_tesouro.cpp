#include <bits/stdc++.h>
using namespace std;

void tesouro(vector<int> &mapa,vector<bool> &caminho, vector<bool> &destino, int linha, int coluna, int n,  int dist, int perc){
	if(perc == dist && destino[linha*n + coluna] != 1){
		mapa[linha*n + coluna]++;	
		destino[linha*n + coluna] = 1 ; 
		return ;
	}
	
	bool cima = linha - 1 >= 0;
	bool baixo = linha + 1 < n;
	bool esquerda = coluna - 1 >= 0;
	bool direita = coluna + 1 < n; 
	
	if(cima && !caminho[(linha - 1)*n + coluna]){
		caminho[linha*n + coluna] = 1; 	
		tesouro(mapa,caminho,destino, linha - 1, coluna, n, dist, perc + 1);	
		caminho[linha*n + coluna] = 0; 
	}
	
	if(baixo && !caminho[(linha + 1)*n + coluna]){
		caminho[linha*n + coluna] = 1; 
		tesouro(mapa,caminho,destino, linha + 1, coluna, n, dist, perc + 1);	
		caminho[linha*n + coluna] = 0;
	}

	if(esquerda && !caminho[linha*n + coluna - 1]){
		caminho[linha*n + coluna] = 1;
		tesouro(mapa, caminho,destino, linha, coluna - 1, n, dist, perc + 1);	
		caminho[linha*n + coluna] = 0;
	}

	if(direita && !caminho[linha*n + coluna + 1]){
		caminho[linha*n + coluna] = 1; 
		tesouro(mapa,caminho,destino, linha, coluna + 1 , n, dist, perc + 1);	
		caminho[linha*n + coluna] = 0;
	}

}

int main(){
	int n, k;
	cin >> n >> k;

	vector<int>mapa(n*n, 0);

	for(int i = 0; i < k; i++){
		int linha, coluna, dist;
		cin >> linha >> coluna >> dist;
		vector<bool>destino(n*n,0);
				vector<bool>caminho(n*n, 0);
		tesouro(mapa, caminho, destino, linha, coluna, n, dist, 0);
	}

	for(int i = 0; i < n*n; i++){
		if(mapa[i] == k){
			cout << i / n << " " << i % n;	
			return 0;
		}	
	}
	
	cout << -1 << " " << -1;	
	return 0;
}
