#include <iostream>
#include <vector>
#include <complex>

using namespace std;

class Matrix {
    public:
        int m, n;
        vector<vector<complex<double>>> mat;
        Matrix(vector<vector<complex<double>>> mat_, int m_, int n_) : mat(mat_), m(m_), n(n_) {};
        void print();
};

void Matrix::print() {
    for (int i=0; i<m; i++) {
        cout << "|";
        for (int j=0; j<n; j++) {
            cout << mat[i][j];
            cout << " ";
        }
        cout << "|\n";
    }
}

Matrix operator+(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.m!=mat2.m || mat1.n!=mat2.n) {
        throw std::runtime_error("Matrices have to be of the same size to add them together");
    }

    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat1.m; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat1.n; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat1.m; i++) {
        for (int j=0; j<mat1.n; j++) {
            ans_vec[i][j] = mat1.mat[i][j] + mat2.mat[i][j];
        }
    }

    Matrix ans = Matrix(ans_vec, mat1.m, mat1.n);

    return ans;
}

Matrix operator+(const Matrix& mat, const complex<double>& num) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.m; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.n; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.m; i++) {
        for (int j=0; j<mat.n; j++) {
            ans_vec[i][j] = mat.mat[i][j] + num;
        }
    }

    Matrix ans = Matrix(ans_vec, mat.m, mat.n);

    return ans;
}

Matrix operator+(const complex<double>& num, const Matrix& mat) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.m; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.n; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.m; i++) {
        for (int j=0; j<mat.n; j++) {
            ans_vec[i][j] = mat.mat[i][j] + num;
        }
    }

    Matrix ans = Matrix(ans_vec, mat.m, mat.n);

    return ans;
}

Matrix operator-(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.m!=mat2.m || mat1.n!=mat2.n) {
        throw std::runtime_error("Matrices have to be of the same size to substract them");
    }

    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat1.m; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat1.n; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat1.m; i++) {
        for (int j=0; j<mat1.n; j++) {
            ans_vec[i][j] = mat1.mat[i][j] - mat2.mat[i][j];
        }
    }

    Matrix ans = Matrix(ans_vec, mat1.m, mat1.n);

    return ans;
}

Matrix operator-(const Matrix& mat, const complex<double>& num) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.m; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.n; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.m; i++) {
        for (int j=0; j<mat.n; j++) {
            ans_vec[i][j] = mat.mat[i][j] - num;
        }
    }

    Matrix ans = Matrix(ans_vec, mat.m, mat.n);

    return ans;
}

Matrix operator-(const complex<double>& num, const Matrix& mat) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.m; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.n; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.m; i++) {
        for (int j=0; j<mat.n; j++) {
            ans_vec[i][j] = num - mat.mat[i][j];
        }
    }

    Matrix ans = Matrix(ans_vec, mat.m, mat.n);

    return ans;
}

Matrix operator*(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.n!=mat2.m) {
        throw std::runtime_error("To multiply two matrices, the number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat1.m; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat2.n; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat1.m; i++) {
        for (int j=0; j<mat2.n; j++) {
            complex<double> sum = 0;
            for (int k=0; k<mat1.n; k++) {
                sum = sum + (mat1.mat[i][k]*mat2.mat[k][j]);
            }
            ans_vec[i][j] = sum;
        }
    }

    Matrix ans = Matrix(ans_vec, mat1.m, mat2.n);

    return ans;
}

Matrix operator*(const complex<double>& num, const Matrix& mat) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.m; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.n; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.m; i++) {
        for (int j=0; j<mat.n; j++) {
            ans_vec[i][j] = num * mat.mat[i][j];
        }
    }

    Matrix ans = Matrix(ans_vec, mat.m, mat.n);

    return ans;
}

Matrix operator*(const Matrix& mat, const complex<double>& num) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.m; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.n; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.m; i++) {
        for (int j=0; j<mat.n; j++) {
            ans_vec[i][j] = num * mat.mat[i][j];
        }
    }

    Matrix ans = Matrix(ans_vec, mat.m, mat.n);

    return ans;
}

Matrix operator/(const Matrix& mat, const complex<double>& num) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat.m; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat.n; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat.m; i++) {
        for (int j=0; j<mat.n; j++) {
            ans_vec[i][j] = mat.mat[i][j] / num;
        }
    }

    Matrix ans = Matrix(ans_vec, mat.m, mat.n);

    return ans;
}

Matrix operator%(const Matrix& mat1, const Matrix& mat2) {
    vector<vector<complex<double>>> ans_vec;
    for (int i = 0; i < mat1.m*mat2.m; i++) {
        vector<complex<double>> row;
        for (int j = 0; j < mat1.n*mat2.n; j++) {
            row.push_back(0);
        }
        ans_vec.push_back(row);
    }
    for (int i=0; i<mat1.m; i++) {
        for (int j=0; j<mat1.n; j++) {
            for (int k=0; k<mat2.m; k++) {
                for (int l=0; l<mat2.n; l++) {
                    ans_vec[i*mat2.m+k][j*mat2.n+l] = mat1.mat[i][j]*mat2.mat[k][l];
                }
            }
        }
    }

    Matrix ans = Matrix(ans_vec, mat1.m*mat2.m, mat1.n*mat2.n);

    return ans;
}