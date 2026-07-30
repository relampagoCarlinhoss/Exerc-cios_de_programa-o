#include <bits/stdc++.h>
using namespace std;

void permuta_rcrs(vector<int> permut, vector<bool> chosen, int n){
	if(permut.size() == n){
		for(int i = 0; i < n; i++){
			if(i == 0){cout << "{";}	
			cout << permut[i];
			if(i == n - 1){cout << "}";}
		}	
		return;
	}
	
	for(int i = 0; i < n; i++){
		if(chosen[i] == true) continue; 
		chosen[i] = true; 
		permut.push_back(i);
		permuta_rcrs(permut, chosen, n);	
		permut.pop_back();
		chosen[i] = false;
	}
}

int main(){
	int n;
	cin >> n; 

	vector<int> permut;
	vector <bool> chosen(n, 0);
	
	permuta_rcrs(permut, chosen, n);

	return 0;
}
