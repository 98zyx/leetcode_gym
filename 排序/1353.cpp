#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    const int N = 1e5;
    typedef pair<int, int> PII;
    typedef pair<pair<int, int>, int> PIII;
    int maxEvents(vector<vector<int>>& events) {
        int ans = 0;
        set<int> v;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        sort(events.begin(), events.end());
        int p = 0;
        for (int i = 0; i <= N; i++) {
            while (p < events.size() && i >= events[p][0]) {
                pq.push(PII{events[p][1], p});
                p++;
            }
            while (pq.size() && pq.top().first < i) {
                pq.pop();
            }
            if (pq.size()) {
                v.insert(pq.top().second);
                pq.pop();
            }
        }
        return v.size(); 
    }
};