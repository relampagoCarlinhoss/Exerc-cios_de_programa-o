using namespace std;
#include <bits/stdc++.h>

int main(){
    int n;
    bool l1 = false, l2 = false;
    cin >> n;
    
    int estado;
    while(n--){
        cin >> estado;


        if(estado == 1){
            l1 = !l1 ;
        }
        
        if(estado == 2){
            l1 = !l1;
            l2 = !l2;
        }
    }

    cout << (int) l1<< "\n"<< (int) l2;
    return 0;
}