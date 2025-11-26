#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main() {
    srand(time(0));

    int n = 100;
    int k = 3;
    int max_iters = 100;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        points[i] = { (double)rand() / RAND_MAX, (double)rand() / RAND_MAX };
    }

    vector<Point> centroids(k);
    for (int i = 0; i < k; i++) {
        centroids[i] = points[rand() % n];
    }

    vector<int> labels(n);

    for (int iter = 0; iter < max_iters; iter++) {
        for (int i = 0; i < n; i++) {
            int best = 0;
            double best_dist = distance(points[i], centroids[0]);
            for (int j = 1; j < k; j++) {
                double d = distance(points[i], centroids[j]);
                if (d < best_dist) {
                    best_dist = d;
                    best = j;
                }
            }
            labels[i] = best;
        }

        vector<Point> new_centroids(k, {0, 0});
        vector<int> counts(k, 0);

        for (int i = 0; i < n; i++) {
            int c = labels[i];
            new_centroids[c].x += points[i].x;
            new_centroids[c].y += points[i].y;
            counts[c]++;
        }

        bool converged = true;
        for (int j = 0; j < k; j++) {
            if (counts[j] > 0) {
                Point updated = { new_centroids[j].x / counts[j], new_centroids[j].y / counts[j] };
                if (distance(updated, centroids[j]) > 1e-6) {
                    centroids[j] = updated;
                    converged = false;
                }
            }
        }

        if (converged) break;
    }

    for (int i = 0; i < n; i++) {
        cout << "Point (" << points[i].x << ", " << points[i].y << ") -> Cluster " << labels[i] << "\n";
    }

    return 0;
}