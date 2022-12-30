#include <iostream>
#include "Matrices.h"
#include <cmath>
#include <bitset>
#include <string>

using namespace std;

class QuantumComputer {
    public:
        Matrix state = Matrix({{CN(1,0)}, {CN(0, 0)}}, 2, 1);
        int qubits;
        QuantumComputer(int qubits_);
        void LN(Matrix m, int qubit);
        void probability();
        Matrix hadamar = Matrix({{CN(1/sqrt(2.0), 0), CN(1/sqrt(2.0), 0)}, {CN(1/sqrt(2.0), 0), CN(-1/sqrt(2.0), 0)}}, 2, 2);
        Matrix pauliX = Matrix({{CN(0, 0), CN(1, 0)}, {CN(1, 0), CN(0, 0)}}, 2, 2);
        Matrix pauliY = Matrix({{CN(0, 0), CN(0, -1)}, {CN(0, 1), CN(0, 0)}}, 2, 2);
        Matrix pauliZ = Matrix({{CN(1, 0), CN(0, 0)}, {CN(0, 0), CN(-1, 0)}}, 2, 2);
        Matrix CX = Matrix({{CN(1, 0), CN(0, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(1, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(0, 0), CN(0, 0), CN(1, 0)}, {CN(0, 0), CN(0, 0), CN(1, 0), CN(0, 0)}}, 4, 4);
        Matrix CZ = Matrix({{CN(1, 0), CN(0, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(1, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(0, 0), CN(1, 0), CN(0, 0)}, {CN(0, 0), CN(0, 0), CN(0, 0), CN(-1, 0)}}, 4, 4);
        Matrix SWAP = Matrix({{CN(1, 0), CN(0, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(0, 0), CN(1, 0), CN(0, 0)}, {CN(0, 0), CN(1, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(0, 0), CN(0, 0), CN(1, 0)}}, 4, 4);
        Matrix CCX = Matrix({{CN(1, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(1, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(0, 0), CN(1, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(0, 0), CN(0, 0), CN(1, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(1, 0), CN(0, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(1, 0), CN(0, 0), CN(0, 0)}, {CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(1, 0)}, {CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(0, 0), CN(1, 0), CN(0, 0)}}, 8, 8);
};

// Matrix({{CN(), CN()}, {CN(), CN()}}, 2, 2);
// Matrix({{CN(), CN(), CN(), CN()}, {CN(), CN(), CN(), CN()}, {CN(), CN(), CN(), CN()}, {CN(), CN(), CN(), CN()}}, 4, 4);

QuantumComputer::QuantumComputer(int qubits_) : qubits(qubits_) {
    for (int i=0; i<qubits-1; i++) {
        state = state%Matrix({{CN(1,0)}, {CN(0, 0)}}, 2, 1);
    }
}

void QuantumComputer::LN(Matrix m, int qubit) {
    int degree = log2(m.m);
    Matrix LN = Matrix({{CN(1, 0)}}, 1, 1);
    for (int i=0; i<qubits; i++) {
        if (i+1==qubit) {
            LN = LN%m;
            i+=degree-1;
        } else {
            LN = LN%Matrix({{CN(1, 0), CN(0, 0)}, {CN(0, 0), CN(1, 0)}}, 2, 2);
        }
    }

    state = LN*state;
}

void QuantumComputer::probability() {
    for (int i=0; i<state.m; i++) {
        if (state.mat[i][0] != CN(0, 0)) {
            bitset<10> b(i);
            string s = b.to_string();
            s.erase(0, 10-qubits);
            cout << s << " - ";
            CN prob = state.mat[i][0];
            prob.x = sqrt((prob.x*prob.x)+(prob.y*prob.y));
            prob.y = 0;
            prob = (prob*prob)*CN(100, 0);
            prob.print();
            cout << "%\n";
        }
    }
}