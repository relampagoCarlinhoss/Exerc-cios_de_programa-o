#include <bits/stdc++.h>
using namespace std;

struct Dragons{
	int forca;
	int bonus;
};

//ordenação_________________________________________________
int particao(vector<Dragons> &d, int left, int right){
	int pivot = d[right].forca;
	int i = left - 1; 

	for(int j = left; j < right; j++){
		if(d[j].forca < pivot){
			i++;
			swap(d[i], d[j]);
		}
	}
	swap(d[i + 1], d[right]);

	return i + 1; 
}

void quick_sort(vector<Dragons> &d, int left, int right){
	if(left >= right){
		return ;
	}

	int pivot = particao(d, left, right);
	quick_sort(d, left, pivot - 1);
	quick_sort(d, pivot + 1, right);
}
//____________________________________________________________

int main(){
	bool venceu = true;
	int k_forca = 0;
	int forca = 0, bonus = 0, q_dragons = 0; 
	cin >> k_forca >> q_dragons; 

	vector<Dragons> inm;
	for(int i = 0; i < q_dragons; i++){
		cin >> forca >> bonus; 
		if(k_forca > forca){
			k_forca += bonus;	
		}

		else{
			inm.push_back({forca, bonus});		
		}
	}

	quick_sort(inm, 0, inm.size() - 1);
	size_t leng = inm.size();
	for(size_t i = 0; i < leng; i++){
		if(inm[i].forca < k_forca){
			k_forca += inm[i].bonus; 	
		}	
		
		else{
			cout << "NO\n";
			return 0; 
		}
	}	

	cout << "YES\n"; 
	return 0;
}
