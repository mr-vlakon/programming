class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i != efficiency.size(); ++i) {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end(), [&](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.first > rhs.first;
        });
        long long answer = 0;
        long long sum = 0;
        priority_queue<int, deque<int>, greater<int>> pqMin;
        for (int j = 0; j != k; ++j) {
            sum += v[j].second;
            if ((sum * v[j].first) > answer) {
                answer = sum * v[j].first;
            }
            pqMin.push(v[j].second);
        }
        priority_queue<int> pq;
        for (int i = k; i != v.size(); ++i) {
            pq.push(v[i].second);
            pqMin.push(v[i].second);
            sum -= pqMin.top();
            sum += pq.top();
            pqMin.pop();
            pq.pop();
            if ((sum * v[i].first) > answer) {
                answer = sum * v[i].first;
            }
        }
        return answer % 1000000007;
    }
};

int main() {
  
  
  
  return 0;  
}
