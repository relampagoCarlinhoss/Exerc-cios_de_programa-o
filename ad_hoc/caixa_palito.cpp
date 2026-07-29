#include <iostream> 
using namespace std;

long long fatorial(long long n){
	long long fatorial = 1; 
	for(long long i = 1; i <= n;i++){ 
		fatorial *= i;  
	}
	return fatorial; 
}

	int main(){
	long long soma, max; 
	cin >> soma >> max; 

	long long  b_lim = max + 1; 
	long long sobra = soma - 3*max; 
	long long res = 0;
	
	if(3*max < soma){ 
		cout << "0";
		return 0;	
	}
	
	res = (fatorial(sobra + 2)/(fatorial (sobra)*2))*3;
	long long exc = (fatorial(b_lim + 2)/fatorial(b_lim)*2)*3;
	long long inc = (fatorial(soma - b_lim*2 + 2)/fatorial(soma - b_lim)*2)*3;		
 	res -= exc + inc;

		cout << res; 
	return 0;
}
