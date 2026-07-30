#include <bits/stdc++.h> 
using namespace std;

int subset(int n, vector<int> subconjuntos, int &q_subset, int k){
	if(k == n){
		q_subset++;
		return q_subset;
	}	
	subset(n, subconjuntos, q_subset, k + 1);
	subconjuntos.push_back(k);
	subset(n, subconjuntos, q_subset, k + 1);
	subconjuntos.pop_back();	

	return q_subset; 
}

int main(){
	int n = 0; 
	int k = 0; 
	int q_subset = 0; 
	vector<int> subconjuntos;
	cin >> n;
	int res = subset(n, subconjuntos, q_subset, k);

	cout << res;  
	return 0;
}
