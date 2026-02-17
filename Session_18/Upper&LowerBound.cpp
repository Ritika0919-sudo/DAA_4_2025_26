#include <iostream>
using namespace std;

int lowerbound(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int ans = n;   // default if not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int upperbound(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int ans = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    int lb = lowerbound(arr, n, target);
    int ub = upperbound(arr, n, target);

    cout << "Count = " << ub - lb << endl;

    return 0;
}
