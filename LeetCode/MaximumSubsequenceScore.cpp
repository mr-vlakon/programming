class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {        
        vector<pair<int, int>> v;
        for (int i = 0; i != nums1.size(); ++i) {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end(), [&](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.first > rhs.first;
        });
        long long answer = 0;
        long long sum = 0;
        priority_queue<int, deque<int>, greater<int>> pqMin;
        for (int j = 0; j != k; ++j) {
            sum += v[j].second;
            pqMin.push(v[j].second);
        }
        priority_queue<int> pq;
        answer = sum * v[k - 1].first;
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
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
