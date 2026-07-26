using namespace std;
#include <bits/stdc++.h>

int main(){
	int n;
	cin >> n; 
	vector<int>pos(n + 1);	
	
	for(int i = 0; i < n; i++){
		int carta;
		cin >> carta; 
		pos[carta] = i;	
	}

	int estado = 1;
	int last = pos[1];
	for(int v = 2; v <= n; v++){
			if(pos[v] < last) estado++;
			last = pos[v];	
		}	
	cout << estado << "\n";
	return 0;
}
