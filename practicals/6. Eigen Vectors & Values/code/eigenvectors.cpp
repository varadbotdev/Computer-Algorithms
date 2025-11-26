#include <bits/stdc++.h>
using namespace std;

const int N = 3; 
const double EPS = 1e-6;
const int MAX_ITER = 1000;

void multiply(double A[N][N], double v[N], double res[N]) {
    for (int i = 0; i < N; i++) {
        res[i] = 0;
        for (int j = 0; j < N; j++) {
            res[i] += A[i][j] * v[j];
        }
    }
}

double dot(double a[N], double b[N]) {
    double s = 0;
    for (int i = 0; i < N; i++) s += a[i] * b[i];
    return s;
}

double norm(double v[N]) {
    return sqrt(dot(v, v));
}

void normalize(double v[N]) {
    double n = norm(v);
    if (n > 0)
        for (int i = 0; i < N; i++) v[i] /= n;
}

int main() {
   
    double A[N][N] = {
        {4, 1, 1},
        {1, 3, 0},
        {1, 0, 2}
    };

    double b[N] = {1, 1, 1}; 
    normalize(b);

    double lambda_old = 0, lambda = 0;
    double Ab[N];

    for (int iter = 0; iter < MAX_ITER; iter++) {
        multiply(A, b, Ab);
        lambda = dot(b, Ab) / dot(b, b); 

        if (fabs(lambda - lambda_old) < EPS) {
            break;
        }

        for (int i = 0; i < N; i++) b[i] = Ab[i];
        normalize(b);
        lambda_old = lambda;
    }

    cout << "Dominant eigenvalue ≈ " << lambda << "\n";
    cout << "Eigenvector ≈ ";
    for (int i = 0; i < N; i++) cout << b[i] << " ";
    cout << "\n";

    return 0;
}