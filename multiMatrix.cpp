
#include <iostream>


using namespace std;

int main()
{
  float A[20][20], B[20][20], C[20][20];
        int n, m;
        float u;
        cout << "Dimension n de A ";
        cin>>n;

        cout << endl;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                cout << "Ingrese valor para A[" << i << "][" << j << "]: ";
                cin >> A[i][j];
            }

        cout << endl;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 1; ++j) {
                cout << "Ingrese valor para B[" << i << "][" << j << "]: ";
                cin >> B[i][j];
            }

        // Inicializamos la matriz C.
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 1; ++j)
                C[i][j] = 0;

        // Generamos la matriz C.
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 1; ++j)
                for (int z = 0; z < n; ++z)
                    C[i][j] += A[i][z] * B[z][j];

        cou<t << "Matriz A: ";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Matriz B: ";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 1; ++j) {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Matriz C: ";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 1; ++j) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    return 0;
}