#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums[nums.size()-1] - nums[0];
        for (int i = 0; i < nums.size()-1; i++) {
            int maxVal = max(nums[i]+k, nums[nums.size()-1]-k);
            int minVal = min(nums[i+1]-k, nums[0]+k);
            ans = min(ans, maxVal-minVal);
        }
        return ans;
    }
};