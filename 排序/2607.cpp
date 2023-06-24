#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        k = gcd(k, arr.size());
        int n = arr.size();
        vector<vector<int>> a(k, vector<int>(0));
        for (int i = 0; i < n; i++) {
            a[i%k].push_back(arr[i]);
        }
        long long ans = 0;
        for (auto &b : a) {
            nth_element(b.begin(), b.begin()+b.size()/2, b.end());
            for (int i = 0; i < b.size(); i++) {
                ans += abs(b[i] - b[b.size()/2]);
            }
        }
        return ans;
   }
};