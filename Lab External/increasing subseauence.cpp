#include <iostream>;
#include <vector>;

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> temp;

    for (int x : nums) {
        auto it = lower_bound(temp.begin(), temp.end(), x);

        if (it == temp.end())
            temp.push_back(x);
        else
            *it = x;
    }

    return temp.size();
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums);
    return 0;
}