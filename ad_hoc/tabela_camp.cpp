#include <bits/stdc++.h> 
using namespace std;

int main(){
	int j, p, v, e, d;
	cin >> j >> p >> v >> e >> d;
	bool j_s = j != -1;
	bool p_s = p != -1; 
	bool v_s = v !=  -1;
	bool e_s = e != -1;
	bool d_s = d != -1;	
	bool cond = (j_s && p_s && v_s && e_s  && d_s);	

	while(cond == false){	
		if(j == -1){
			if(v_s && e_s && d_s){
				j = v + e + d;
				j_s = true; 
			}

			else if(p_s && d_s && v_s){
				j = p + d - 2*v; 	
				j_s = true; 
			} 
		}

		if(p == -1){
			if(v_s && e_s){
				p = 3*v + e;			
				p_s = true; 
			}	

			else if(v_s && j_s && d_s){
				p = 2*v + j - d; 	
				p_s = true; 
			}
		}

		if(v == -1){
			if(p_s && e_s){
				v = (p - e)/ 3; 	
				v_s = true; 
			}	

			else if(j_s && d_s && e_s){
				v = j - d - e;	
				v_s = true; 
			}
			
			else if(d_s && p_s && j_s){
				v = (d + p - j)/2;
				v_s = true; 	
			}
		}
		
		if(d == -1){
			if(j_s && v_s && e_s){
				d = j - v - e;	
				d_s = true; 
			}	

			else if(v_s && j_s && p_s){
				d = 2*v + j - p;		
				d_s = true; 
			}
		}

		if(e == -1){
			if(p_s && v_s){
				e = p - 3*v;	
				e_s = true; 
			}	

			else if(j_s && v_s && d_s){
				e = j - v - d;	
				e_s = true; 	
			}
		}

		cond = (j_s && p_s && v_s && e_s  && d_s);	
	}

	cout << j << " " << p << " " << v << " " << e << " " <<  d; 
	return 0;
}
