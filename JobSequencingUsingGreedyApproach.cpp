// WAP to perform job sequencing with deadline using greedy approach.

#include <iostream>
#include <algorithm>
using namespace std;
struct Job {
    int id;
    int deadline;
    int profit;
};
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}
void jobSequencing(Job arr[], int n) {
    sort(arr, arr + n, compare);
    int result[n];
    bool slot[n];
    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }       
    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = arr[i].id;
                break;
            }
        }
    }
    cout << "Job sequence: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    Job arr[n]; 
    for (int i = 0; i < n; i++) {
        cout << "Enter deadline and profit of J" << i+1 << " job: ";
        cin >> arr[i].deadline >> arr[i].profit;
        arr[i].id = i + 1;
    }
    jobSequencing(arr, n);
    return 0;
}