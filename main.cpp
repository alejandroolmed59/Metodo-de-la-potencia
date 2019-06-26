
#include <iostream>


using namespace std;

int main() {
    float A[20][20], B[20][20], C[20][20];
    int n, m, N;
    float u;
    cout << "Dimension n de A ";
    cin>>n;
    cout << "Numero máximo de iteraciones ";
    cin>>N;
    cout << endl;
    // MATRIZ A No cambiante
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cout << "Ingrese valor para A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    cout << endl;
    // ES el VECTOR, este es el x(0)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 1; ++j) {
            cout << "Ingrese valor para B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }


    for (int a = 1; a <= N; a++) {
        cout<<endl;
        cout<< "Iteracion: "<<a<<endl;
        // Inicilizar matriz nula C (se usa como deposito del vector x(n) )
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 1; ++j)
                C[i][j] = 0;
        // Llenar C (x(n))
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 1; ++j)
                for (int z = 0; z < n; ++z)
                    C[i][j] += A[i][z] * B[z][j];
            
        //Segun un tipo de yt, dado que el producto de A^k*x da un valor muy grande, se normalizará la matríz de estos productos dividiendo cada
        //elemento del vector resultante por la coordenada de dicho vector que tenga mayor valor abs}

        float mayor = C[0][0];
        // Se obtiene el dato mayor para normalizar la matriz (valor característico!!! )
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 1; ++j) {
                if (C[i][j] > mayor) {
                    mayor = C[i][j];
                }
            }
        }
        
        
        //SI es la última iteracion, es el vector característico
        cout<<"VEctor caracteristico"<<endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 1; ++j) {
                C[i][j] = C[i][j] / mayor;
                cout <<"x(" <<a<<") " <<"["<<i<<"]["<<j<<"]= " << C[i][j]<<"  ";
               
            }
            cout <<endl;
        }
        
        cout <<"Valor característico (u): "<< mayor << endl;
        // Se prepara la matriz B (normalizada) para la siguiente iteración
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 1; ++j) {
                B[i][j]= C[i][j];
            }
        }

    }
    return 0;
}