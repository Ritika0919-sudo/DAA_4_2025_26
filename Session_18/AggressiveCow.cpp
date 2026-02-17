#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int aggressiveCows(int *stalls, int n, int k) {

    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int count = 1;
        int lastPos = stalls[0];

        for(int i = 1; i < n; i++) {
            if(stalls[i] - lastPos >= mid) {
                count++;
                lastPos = stalls[i];
            }
        }

        if(count >= k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}
