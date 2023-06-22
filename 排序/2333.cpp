#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef long long ll;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        ll ans = 0;
        int n = nums1.size();
        vector<int> diff(n+1);
        for (int i = 0; i < n; i++) {
            diff[i+1] = abs(nums1[i] - nums2[i]);
            ans += ll(diff[i+1]) * ll(diff[i+1]);
        }
        sort(diff.begin(), diff.end());
        int k = k1 + k2;
        for (int i = n; i > 0; i--) {
            if (k == 0) return ans;
            ll cur_diff = diff[i] - diff[i-1]; 
            ll area = cur_diff * (n-i+1);
            if (area <= k) {
                ans -= (n-i+1) * (2 * cur_diff * diff[i] - cur_diff * cur_diff);
                k -= area;
            } else {
                ll x = k / (n-i+1);
                ans -= (n-i+1) * (2 * x * diff[i] - x * x);
                ll cur_pos = diff[i] - x;
                k -= x * (n-i+1);
                ans -= k * (2 * cur_pos - 1);
                k = 0;
            }
        }
        return ans;
    }
};