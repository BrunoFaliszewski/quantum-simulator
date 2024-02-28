#include <iostream>
#include <vector>
#include <complex>

using namespace std;

class Matrix {
    public:
        int n, m;
        vector<vector<complex<double>>> mat;
        Matrix(vector<vector<complex<double>>> mat_, int n_, int m_) : mat(mat_), n(n_), m(m_) {};
        void print();
};


/**
 * Prints human-readable representation of a matrix.
 */
void Matrix::print() {
    for (int i=0; i<n; i++) {
        cout << "|";
        for (int j=0; j<m; j++) {
            cout << mat[i][j];
            cout << " ";
        }
        cout << "|\n";
    }
}


/**
 * Addition of 2 matrices.
 */
Matrix operator+(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.n!=mat2.n || mat1.m!=mat2.m) {
        throw std::runtime_error("Matrices have to be of the same size to add them together");
    }

    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat1.n; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat1.m; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat1.n; i++) {
        for (int j=0; j<mat1.m; j++) {
            ans_vec[i][j] = mat1.mat[i][j] + mat2.mat[i][j];
        }
    }

    Matrix ans = Matrix(ans_vec, mat1.n, mat1.m);

    return ans;
}


/**
 * Addition of a matrix to a constant.
 */
Matrix operator+(const Matrix& mat, const complex<double>& num) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.n; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.m; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.n; i++) {
        for (int j=0; j<mat.m; j++) {
            ans_vec[i][j] = mat.mat[i][j] + num;
        }
    }

    Matrix ans = Matrix(ans_vec, mat.n, mat.m);

    return ans;
}


/**
 * Addition of a constant to a matrix.
 */
Matrix operator+(const complex<double>& num, const Matrix& mat) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.n; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.m; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.n; i++) {
        for (int j=0; j<mat.m; j++) {
            ans_vec[i][j] = mat.mat[i][j] + num;
        }
    }

    Matrix ans = Matrix(ans_vec, mat.n, mat.m);

    return ans;
}


/**
 * Substitution of a matrix from a matrix.
 */
Matrix operator-(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.n!=mat2.n || mat1.m!=mat2.m) {
        throw std::runtime_error("Matrices have to be of the same size to substract them");
    }

    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat1.n; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat1.m; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat1.n; i++) {
        for (int j=0; j<mat1.m; j++) {
            ans_vec[i][j] = mat1.mat[i][j] - mat2.mat[i][j];
        }
    }

    Matrix ans = Matrix(ans_vec, mat1.n, mat1.m);

    return ans;
}


/**
 * Substitution of a constant from a matrix.
 */
Matrix operator-(const Matrix& mat, const complex<double>& num) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.n; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.m; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.n; i++) {
        for (int j=0; j<mat.m; j++) {
            ans_vec[i][j] = mat.mat[i][j] - num;
        }
    }

    Matrix ans = Matrix(ans_vec, mat.n, mat.m);

    return ans;
}


/**
 * Substitution of a matrix from a number.
 */
Matrix operator-(const complex<double>& num, const Matrix& mat) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.n; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.m; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.n; i++) {
        for (int j=0; j<mat.m; j++) {
            ans_vec[i][j] = num - mat.mat[i][j];
        }
    }

    Matrix ans = Matrix(ans_vec, mat.n, mat.m);

    return ans;
}


/**
 * Product of 2 matrices.
 */
Matrix operator*(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.m!=mat2.n) {
        throw std::runtime_error("To multiply two matrices, the number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat1.n; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat2.m; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat1.n; i++) {
        for (int j=0; j<mat2.m; j++) {
            complex<double> sum = 0;
            for (int k=0; k<mat1.m; k++) {
                sum = sum + (mat1.mat[i][k]*mat2.mat[k][j]);
            }
            ans_vec[i][j] = sum;
        }
    }

    Matrix ans = Matrix(ans_vec, mat1.n, mat2.m);

    return ans;
}


/**
 * Multiplication of a matrix by a scalar.
 */
Matrix operator*(const complex<double>& num, const Matrix& mat) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.n; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.m; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.n; i++) {
        for (int j=0; j<mat.m; j++) {
            ans_vec[i][j] = num * mat.mat[i][j];
        }
    }

    Matrix ans = Matrix(ans_vec, mat.n, mat.m);

    return ans;
}


/**
 * Multiplication of a matrix by a scalar.
 */
Matrix operator*(const Matrix& mat, const complex<double>& num) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.n; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.m; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.n; i++) {
        for (int j=0; j<mat.m; j++) {
            ans_vec[i][j] = num * mat.mat[i][j];
        }
    }

    Matrix ans = Matrix(ans_vec, mat.n, mat.m);

    return ans;
}


/**
 * Division of a matrix by a constant.
 */
Matrix operator/(const Matrix& mat, const complex<double>& num) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.n; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.m; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.n; i++) {
        for (int j=0; j<mat.m; j++) {
            ans_vec[i][j] = mat.mat[i][j] / num;
        }
    }

    Matrix ans = Matrix(ans_vec, mat.n, mat.m);

    return ans;
}


/**
 * Tensor product of 2 matrices.
 */
Matrix operator%(const Matrix& mat1, const Matrix& mat2) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat1.n*mat2.n; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat1.m*mat2.m; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat1.n; i++) {
        for (int j=0; j<mat1.m; j++) {
            for (int k=0; k<mat2.n; k++) {
                for (int l=0; l<mat2.m; l++) {
                    ans_vec[i*mat2.n+k][j*mat2.m+l] = mat1.mat[i][j]*mat2.mat[k][l];
                }
            }
        }
    }

    Matrix ans = Matrix(ans_vec, mat1.n*mat2.n, mat1.m*mat2.m);

    return ans;
}