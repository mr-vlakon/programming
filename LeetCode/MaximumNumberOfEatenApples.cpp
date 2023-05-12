class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, deque<pair<int, int>>, greater<pair<int, int>>> pq;
        if (apples[0] > 1 && (days[0] > 1)) {
            pq.push({days[0], apples[0] - 1});
        }
        int days_ = 0;
        int apples_ = 0;
        if (apples[0] >= 1) {
            days_ = 1;
            apples_ = 1;
        }
        pair<int, int> top;
        days_ = 1;
        for (int i = 1; i != apples.size(); ++i) {
            if (apples[i] != 0) {
                if ((days[i] + i) > days_) {
                    pq.push({days[i] + i, apples[i]});
                }
            }
            while (!pq.empty() && days_ >= pq.top().first) {
                pq.pop();
            }
            if (!pq.empty()) {
                top = pq.top();
                ++apples_;
                pq.pop();
                if (top.second > 1 && (top.first) > (days_ + 1)) {
                    pq.push({top.first, top.second - 1});
                }
            }
            ++days_;      
        }
        int t = 0;
        while (!pq.empty()) {
            while (!pq.empty() && days_ >= pq.top().first) {
                pq.pop();
            }
            if (!pq.empty()) {
                top = pq.top();
                t = min(abs(days_ - pq.top().first), pq.top().second);
                apples_ += t;
                days_ += t;
                pq.pop();
            }
        }
        return apples_;
    }
};

int main() {
  
  return 0;  
}
