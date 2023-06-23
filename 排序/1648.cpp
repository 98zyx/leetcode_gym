#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    typedef long long ll;
    const ll mod = 1e9+7;
    int maxProfit(vector<int>& in, int orders) {
        vector<ll> inventory(in.size());
        for (int i = 0; i < in.size(); i++) inventory[i] = ll(in[i]);
        sort(inventory.begin(), inventory.end());
        reverse(inventory.begin(), inventory.end());
        inventory.push_back(0);
        ll ans = 0;
        for (int i = 0; i < inventory.size()-1; i++) {
            ll height = (inventory[i] - inventory[i+1]);
            ll width = i+1;
            ll area = (height * width);
            if (area <= orders) {
                ans = (ans + ll(inventory[i] + inventory[i+1] + 1) * ll(height) / 2 * width);
                orders -= area;
            } else {
                height = orders / width;
                ans = (ans + (ll((inventory[i] + inventory[i]) - height + 1) * ll(height) / 2 * width));
                orders -= height * width;
                ans = (ans + (inventory[i] - height) * orders);
                orders = 0;
            }
            ans = ans % mod;
        }
        return ans;
    }
};