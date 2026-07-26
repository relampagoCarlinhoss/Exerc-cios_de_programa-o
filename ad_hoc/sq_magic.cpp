#include <bits/stdc++.h>
using namespace std;

int verificar(int soma, int n, const vector<int>& arr){
    int somaL = 0, somaC = 0, somaD = 0, somaE = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            somaL += arr[i*n + j];
            somaC += arr[j*n + i];
        }
        
        if(somaL != soma || somaC != soma){
            return -1;
        }

        somaL = 0; 
        somaC = 0;
        
        somaD += arr[i*n + i];
        somaE += arr[i*n + (n - i - 1)];
    }

    // Agora sim validando as diagonais no final!
    if(somaD != soma || somaE != soma){
        return -1;
    }

    return soma;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> quad(n * n);

    for(int i = 0; i < n*n; i++){
        cin >> quad[i];
    }

    int soma = 0;
    for(int j = 0; j < n; j++){
        soma += quad[j]; 
    }

    cout << verificar(soma, n, quad) << "\n";
    return 0;
}