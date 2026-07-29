#include <iostream> 
using namespace std;

unsigned long long comb(unsigned long long n){
	unsigned long long res = 0; 
	n += 2;  
	res = (n*(n - 1))/2; 

	return res;
}

int main(){
	unsigned long long soma, max; 
	cin >> soma >> max; 
	
	if(3*max < soma){ 
		cout << "0";
		return 0;	
	}
	soma -= 3; 
	max  -= 1; 

	unsigned long long  b_lim = max + 1; 
	unsigned long long sobra1 = soma - b_lim;	
	unsigned long long sobra2 = soma - b_lim*2; 
	unsigned long long res = 0;
	
	unsigned long long total_casos = comb(soma); 
	unsigned long long invalido1_casos = soma >= b_lim ? comb(sobra1)*3 : 0;
	unsigned long long invalido2_casos = soma >= b_lim*2 ?  comb(sobra2)*3: 0;		
		
	res = total_casos - invalido1_casos + invalido2_casos;	

	cout << res;
	return 0;
}
