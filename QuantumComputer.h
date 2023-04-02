#include <iostream>
#include "Matrices.h"
#include <cmath>
#include <bitset>
#include <string>

using namespace std;

class QuantumComputer {
    public:
        Matrix state = Matrix({{1}, {0}}, 2, 1);
        int qubits;
        QuantumComputer(int qubits_);
        void LN(Matrix m, int qubit);
        void probability();
        Matrix hadamar = Matrix({{1/sqrt(2.0), 1/sqrt(2.0)}, {1/sqrt(2.0), -1/sqrt(2.0)}}, 2, 2);
        Matrix pauliX = Matrix({{0, 1}, {1, 0}}, 2, 2);
        Matrix pauliY = Matrix({{0, -1i}, {1i, 0}}, 2, 2);
        Matrix pauliZ = Matrix({{1, 0}, {0, -1}}, 2, 2);
        Matrix CX = Matrix({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}}, 4, 4);
        Matrix CZ = Matrix({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, -1}}, 4, 4);
        Matrix SWAP = Matrix({{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}}, 4, 4);
        Matrix CCX = Matrix({{1, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 0}}, 8, 8);
};

// Matrix({{CN(), CN()}, {CN(), CN()}}, 2, 2);
// Matrix({{CN(), CN(), CN(), CN()}, {CN(), CN(), CN(), CN()}, {CN(), CN(), CN(), CN()}, {CN(), CN(), CN(), CN()}}, 4, 4);

QuantumComputer::QuantumComputer(int qubits_) : qubits(qubits_) {
    for (int i=0; i<qubits-1; i++) {
        state = state%Matrix({{1}, {0}}, 2, 1);
    }
}

void QuantumComputer::LN(Matrix m, int qubit) {
    int degree = log2(m.m);
    Matrix LN = Matrix({{1}}, 1, 1);
    for (int i=0; i<qubits; i++) {
        if (i==qubit) {
            LN = LN%m;
            i+=degree-1;
        } else {
            LN = LN%Matrix({{1, 0}, {0, 1}}, 2, 2);
        }
    }

    state = LN*state;
}

void QuantumComputer::probability() {
    for (int i=0; i<state.m; i++) {
        if (state.mat[i][0] != 0.0) {
            int n = i;
            string s;
            for(int i = 0; i<log2(state.m); i++) {
                s=(n%2==0 ?"0":"1")+s; n/=2;
            }
            cout << s << " - ";
            double prob = abs(state.mat[i][0])*abs(state.mat[i][0])*100;
            cout << prob;
            cout << "%\n";
        }
    }
}