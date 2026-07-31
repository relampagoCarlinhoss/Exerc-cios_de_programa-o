#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n; 

	vector<int> permt;	
	for(int i = 0; i < n; i++){
		permt.push_back(i);	
	}
	
	do{
		for(int i = 0 ; i < n; i++){
			if(i == 0){ cout << "{";}		
			cout << permt[i] << ",";
			if(i == n - 1){ cout << "}";}
		}	
	
	}while(next_permutation(permt.begin(),permt.end()));

	return 0;
}
