#include <bits/stdc++.h>
using namespace std;

struct Vector {
    double x, y;
};

double distance(Vector a, Vector b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main() {
    srand(time(0));

    const int N = 200;   
    const int k = 4;     
    const int max_iters = 50;

 
    vector<Vector> inputs(N);
    for (int i = 0; i < N; i++) {
        inputs[i] = { (double)rand() / RAND_MAX, (double)rand() / RAND_MAX };
    }

    vector<Vector> codebook(k);
    for (int i = 0; i < k; i++) {
        codebook[i] = inputs[rand() % N];
    }

    vector<int> assignment(N);

    for (int iter = 0; iter < max_iters; iter++) {
       
        for (int i = 0; i < N; i++) {
            int best = 0;
            double best_dist = distance(inputs[i], codebook[0]);
            for (int j = 1; j < k; j++) {
                double d = distance(inputs[i], codebook[j]);
                if (d < best_dist) {
                    best_dist = d;
                    best = j;
                }
            }
            assignment[i] = best;
        }

       
        vector<Vector> new_codebook(k, {0, 0});
        vector<int> count(k, 0);
        for (int i = 0; i < N; i++) {
            int c = assignment[i];
            new_codebook[c].x += inputs[i].x;
            new_codebook[c].y += inputs[i].y;
            count[c]++;
        }

        bool converged = true;
        for (int j = 0; j < k; j++) {
            if (count[j] > 0) {
                Vector updated = { new_codebook[j].x / count[j], new_codebook[j].y / count[j] };
                if (distance(updated, codebook[j]) > 1e-6) {
                    codebook[j] = updated;
                    converged = false;
                }
            }
        }

        if (converged) break;
    }

    cout << "Final codebook:\n";
    for (int i = 0; i < k; i++) {
        cout << "Codevector " << i << ": (" << codebook[i].x << ", " << codebook[i].y << ")\n";
    }

    return 0;
}