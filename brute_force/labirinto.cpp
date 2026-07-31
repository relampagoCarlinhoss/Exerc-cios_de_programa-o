#include <bits/stdc++.h> 
using namespace std;

bool eh_livre(int l, int c, int n, const vector<bool> &pos) {
    if (l < 0 || l >= n || c < 0 || c >= n) return false;
    return pos[l * n + c] == 0;
}

void solucoes_lab(vector<bool> &pos, int n, int l, int c, int perc, int &sol){

	bool cima_e  = (l - 1 >= 0);
	bool baixo_e = (l + 1 < n);
	bool esqrd_e = (c - 1 >= 0);
	bool drt_e   = (c + 1 < n);

	int cima = n*l + c - n;
	int baixo = n*l + c + n;
	int esqrd = n*l + c - 1;
	int drt = n*l + c + 1;
	

	if(perc == n*n && l*n + c == n*n - 1){
		sol++;
		return;	
	}	

	bool c_livre = eh_livre(l - 1, c, n, pos); 
	bool b_livre = eh_livre(l + 1, c, n, pos);
    	bool e_livre = eh_livre(l, c - 1, n, pos);
    	bool d_livre = eh_livre(l, c + 1, n, pos);

    	if (!c_livre && !b_livre && e_livre && d_livre) return;
    	if (!e_livre && !d_livre && c_livre && b_livre) return;
	if(l*n + c == n*n - 1) return ;

		if(cima_e && pos[cima] == 0){
			pos[cima] = 1;	
			solucoes_lab(pos, n, l - 1, c, perc + 1, sol);
			pos[cima] = 0; 
		}

		if(baixo_e && pos[baixo] == 0){
			pos[baixo] = 1;	
			solucoes_lab(pos, n, l + 1, c, perc + 1, sol);
			pos[baixo] = 0;
		}

		if(esqrd_e && pos[esqrd] == 0 ){
			pos[esqrd] = 1;
			solucoes_lab(pos, n, l, c - 1, perc + 1, sol);
			pos[esqrd]= 0;
		}

		if(drt_e && pos[drt] == 0){
			pos[drt] = 1;	
			solucoes_lab(pos, n, l, c + 1, perc + 1, sol);
			pos[drt] = 0;
		}
		
		return; 
}

int main(){
	int n;
	cin >> n;

	vector<bool> pos(n*n, 0);
	int perc = 1, sol = 0;
	pos[0]= true;	
	pos[1] = true;
	solucoes_lab(pos, n, 0, 1, 2, sol);
	cout << sol*2;
	return 0;
}
