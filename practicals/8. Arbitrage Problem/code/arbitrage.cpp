#include <bits/stdc++.h>
using namespace std;

bool detectArbitrage(vector<vector<double>>& rates) {
    int n = rates.size();
    vector<double> dist(n, 1e9);
    dist[0] = 0;


    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (rates[u][v] > 0) {
                    double w = -log(rates[u][v]);
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
    }


    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (rates[u][v] > 0) {
                double w = -log(rates[u][v]);
                if (dist[u] + w < dist[v]) {
                    return true; 
                }
            }
        }
    }
    return false;
}

int main() {
   
    vector<vector<double>> rates = {
        {1,     0.9,   0.8},   // USD
        {1.1,   1,     0.9},   // EUR
        {1.2,   1.1,   1}      // GBP
    };

    if (detectArbitrage(rates)) {
        cout << "Arbitrage opportunity detected!\n";
    } else {
        cout << "No arbitrage opportunity.\n";
    }

    return 0;
}