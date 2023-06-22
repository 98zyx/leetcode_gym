#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)   {
            a[i] = make_pair(aliceValues[i]+bobValues[i], i);
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int av = 0, bv = 0;
        for (int i = 0; i < n; i++)  {
            if (i % 2) bv += bobValues[a[i].second];
            else av += aliceValues[a[i].second];
        }
        if (av > bv) return 1;
        else if (av == bv) return 0;
        else return -1;
    }
};