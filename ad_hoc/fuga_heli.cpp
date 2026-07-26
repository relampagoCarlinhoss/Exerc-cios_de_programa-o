using namespace std;
#include <iostream> 

int main(){
	int heli, polic, fugit, direc;
	cin >> heli >> polic >> fugit >> direc;
	
	while (fugit != polic && fugit != heli){
		fugit = (fugit + direc + 16) % 16;	
		
		if(fugit == heli){
			cout << "S";
		}		

		if(fugit == polic){
			cout << "N";	
		}
	
	}
	return 0;
}
