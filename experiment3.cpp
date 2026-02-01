#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;

    unordered_map<int, int> firstIndex;
    firstIndex[0] = -1;

    int sum = 0, maxLen = 0;
    char ch;

    for (int i = 0; i < N; i++) {
        cin >> ch;

        if (ch == 'P') sum++;
        else if (ch == 'A') sum--;

        if (firstIndex.count(sum))
            maxLen = max(maxLen, i - firstIndex[sum]);
        else
            firstIndex[sum] = i;
    }

    cout << maxLen;
    return 0;
}

/*INPUT :
6
P A P A P P
OUTPUT:
4*/
