// WAP to implement subset sum problem using backtracking approach.

#include <iostream>
using namespace std;
void subsetSum(int arr[], int n, int sum, int subset[], int subsetSize, int index) {
    if (sum == 0) {
        cout << "Subset found: ";
        for (int i = 0; i < subsetSize; i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }
    if (index >= n || sum < 0) {
        return;
    }

    // Include the current element
    subset[subsetSize] = arr[index];
    subsetSum(arr, n, sum - arr[index], subset, subsetSize + 1, index + 1);

    // Exclude the current element
    subsetSum(arr, n, sum, subset, subsetSize, index + 1);
}
int main() {
    int n;
    int arr[50];
    int sum;

    cout << "Enter number of elements: ";
    cin >> n;


    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> sum;

    int subset[50];
    subsetSum(arr, n, sum, subset, 0, 0);
    return 0;
}