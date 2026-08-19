#include <bits/stdc++.h>
using value_type = int; 
using namespace std;

int main(){
	value_type taxi_n{0};
	value_type q_grupos{0};
	value_type c1{0};
	value_type c2{0};
	value_type c3{0};
	value_type c4{0};

	cin >> q_grupos; 
	value_type grupo;
	for(int i = 0; i < q_grupos; i++){
		cin >> grupo;

		if(grupo == 1){
			c1++;
		}	
	
		if(grupo == 2){
			c2++;		
		}	
		
		if(grupo == 3){
			c3++;	
		}	
		
		if(grupo == 4){
			c4++;	
		}
	}
	
	taxi_n += c4;
	c4 = 0;
	
	taxi_n += c3; 
	c1 = c1 > c3 ? c1 - c3 : 0;	
	c3 = 0;	
	
	taxi_n += c2/2;
	c2 %= 2;
	
       if(c2 == 1){
      		taxi_n++;
	       c1 = max(0, c1 - 2);	
        }	

	if(c1 > 0){
		taxi_n += (c1 + 3)/4;	
	} 
	cout << taxi_n << "\n";
	return 0;
}
