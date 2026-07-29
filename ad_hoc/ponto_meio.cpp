using namespace std;
#include <bits/stdc++.h> 

int main(){
	double  q_passos;
	cin >> q_passos;

	double fator =std::sqrt(std::pow(4,q_passos)) + 1;
	double res = std::pow(fator, 2);	
	cout << res; 

	return 0;

}
