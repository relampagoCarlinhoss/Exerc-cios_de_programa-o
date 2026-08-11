#include <bits/stdc++.h>
using namespace std;

void subconjunto(vector<long long> &set,long long &excl, long long n, long long mmc_atual, int idx, int size_set){
	if(size_set != 0){
		if(size_set % 2 == 0){
			excl -= n/mmc_atual; 		
		}	
		
		else{
			excl += n/mmc_atual;	
		}
	}

	for(int i = idx; i < set.size(); i++){
		if(set[i]*mmc_atual > n){
			break;  	
		}	

		subconjunto(set, excl, n, set[i]*mmc_atual, i+ 1, size_set + 1);
	}
}

int main(){
	long long n; 
	int q_primos;
	long long excl = 0; 
	cin >> n >> q_primos;	

	vector<long long> set(q_primos); 
       	for(int i = 0; i < q_primos; i++){
		cin >> set[i];
	}	
	sort(set.begin(), set.end());

	subconjunto(set, excl, n, 1, 0, 0);	
	
	long long incl = n - excl; 
	cout << incl;
	return 0;
}
