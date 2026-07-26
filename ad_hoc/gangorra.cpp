#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p1, p2, c1, c2, pt1,pt2;
    cin >> p1 >> c1 >> p2 >> c2;
    
    pt1 = p1*c1;
    pt2 = p2*c2;

    if(pt1 > pt2){
        cout << -1;
    }

    else if(pt1 < pt2){
        cout << 1;
    }
    
    else{
        cout << 0;
    }

    return 0;
}