#include <bits/stdc++.h> 
using namespace std;
using value_type = int; 

void inversor(map<string,int> &nomes, set<string> const nomes_c, map<int, string> &nomes_v){
	for(auto i:nomes_c){
		nomes_v.insert({nomes[i], i});	
	}
}

int main(){
	int recp{0};
	cin >> recp;
	map<string, int> nomes;
	set<string> nomes_c; 	

	string nome_i{""}; 
	int pos{0}; 
	for(int i = 0; i < recp; i++){
		cin >> nome_i;		
		nomes_c.insert(nome_i);

		auto it = nomes.find(nome_i);
		if(it == nomes.end()){
			nomes.insert({nome_i, pos});			
			pos++;
		}	
		
		else{
			nomes[it->first] = pos;	
			pos++;
		}
	}

	map<int, string> nomes_v;
	inversor(nomes, nomes_c, nomes_v);

	for(auto it = nomes_v.rbegin(); it != nomes_v.rend(); it++){
		cout << it->second << "\n"; 
	}
	return 0; 
}
