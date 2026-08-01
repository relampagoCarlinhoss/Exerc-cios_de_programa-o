#include <bits/stdc++.h> 
using namespace std;

int face_oposta(vector<int> &torre, int linha, int valor){
    int a = linha*6, b = linha*6+1, c = linha*6+2, d = linha*6+3, e = linha*6+4, f = linha*6+5;
    if (torre[a] == valor) return torre[f];
    if (torre[b] == valor) return torre[d];
    if (torre[c] == valor) return torre[e];
    if (torre[d] == valor) return torre[b];
    if (torre[e] == valor) return torre[c];
    if (torre[f] == valor) return torre[a];
    return -1;
}

int main(){
	int tam;
	int maior_soma = -1; 
	cin >> tam;

	vector<int>torre(tam*6);

	for(int i = 0; i < tam*6; i++){cin >> torre[i];}
	
	for(int topo = 0; topo < 6; topo++){
		int topo_atual = torre[topo];	
		int soma = 0;
		bool valido = true;	

		for(int linha = 0; linha < tam; linha++){
			int a = linha*6, b = linha*6+1, c = linha*6+2, d = linha*6+3, e = linha*6+4, f = linha*6+5;
			
			int base = face_oposta(torre, linha, topo_atual);
			if(base == -1){valido = false; break;}

			int melhor_lateral = -1;
			for(int idx : {a,b,c,d,e,f}){
				if(torre[idx] != base && torre[idx] != topo_atual){
					melhor_lateral =  max(melhor_lateral, torre[idx]);	
				}	
			}

			soma += melhor_lateral;
			topo_atual = base; 
		}

		if(valido) maior_soma = max(maior_soma, soma);
	}

	cout << maior_soma; 
	return 0;
}
