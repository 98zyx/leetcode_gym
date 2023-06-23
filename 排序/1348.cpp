#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

class TweetCounts {
public:
    typedef pair<int, int> PII;
    typedef pair<pair<int, int>, int> PIII;
    unordered_map<string, map<int, int>> m; 
    const int minute_unit = 60, hour_unit = 60*60, day_unit = 60*60*24;
    TweetCounts() {

    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if (!m.count(tweetName)) return vector<int>();
        auto unit = (freq == "minute") ? minute_unit : ((freq == "hour") ? hour_unit : day_unit);
        auto ans = vector<int>((endTime - startTime) / unit + 1);
        auto lower = m[tweetName].lower_bound(startTime);
        auto upper = m[tweetName].upper_bound(endTime);
        for (auto p = lower; p != upper; p++) {
            ans[(p->first - startTime) / unit] += p->second;
        }
        return ans;
   }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */