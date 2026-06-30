// WAP to implement matrix chain multiplication using Dynamic Programming approach.


#include <iostream>
#include <climits>
using namespace std;
int matrixChainOrder(int p[], int n) {
    int m[50][50] = {0};

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[0][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    
    int p[100];
    cout << "Enter the dimensions (p[0] to p[" << n << "]): " << endl;
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
    
    int result = matrixChainOrder(p, n);
    cout << "\nMinimum number of  multiplications is: " << result << endl;
    
    return 0;
}