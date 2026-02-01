#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> mp;
    mp[0] = -1;   // base case

    int sum = 0, maxLen = 0;
    char ch;

    for (int i = 0; i < N; i++) {
        cin >> ch;

        if (ch == 'P')
            sum += 1;
        else
            sum -= 1;

        if (mp.find(sum) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    cout << maxLen;
    return 0;
}


/*INPUT :
6
P A P A P P
OUTPUT:
4*/

