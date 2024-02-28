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
        void LO(Matrix m, int qubit);
        void probability();

        // Default gates
        Matrix hadamar = Matrix({{1/sqrt(2.0), 1/sqrt(2.0)}, {1/sqrt(2.0), -1/sqrt(2.0)}}, 2, 2);
        Matrix pauliX = Matrix({{0, 1}, {1, 0}}, 2, 2);
        Matrix pauliY = Matrix({{0, -1i}, {1i, 0}}, 2, 2);
        Matrix pauliZ = Matrix({{1, 0}, {0, -1}}, 2, 2);
        Matrix CX = Matrix({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}}, 4, 4);
        Matrix CZ = Matrix({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, -1}}, 4, 4);
        Matrix SWAP = Matrix({{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}}, 4, 4);
        Matrix CCX = Matrix({{1, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 0}}, 8, 8);
};

QuantumComputer::QuantumComputer(int qubits_) : qubits(qubits_) {
    for (int i=0; i<qubits-1; i++) {
        state = state%Matrix({{1}, {0}}, 2, 1);
    }
}


/**
 * Linear operation on a qubit system.
 * 
 * @param matrix Matrix that will be applied during the linear operation.
 * @param qubit The index of qubit that the linear operation will be applied on.
 */
void QuantumComputer::LO(Matrix matrix, int qubit) {
    int degree = log2(matrix.m);
    Matrix LO = Matrix({{1}}, 1, 1);
    for (int i=0; i<qubits; i++) {
        if (i==qubit) {
            LO = LO%matrix;
            i+=degree-1;
        } else {
            LO = LO%Matrix({{1, 0}, {0, 1}}, 2, 2);
        }
    }

    state = LO*state;
}


/**
 *Calculates and prints the probabilities of collapsing to certain states. 
 */
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