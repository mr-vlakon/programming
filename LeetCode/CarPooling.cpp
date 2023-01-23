class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int> &lhs, vector<int> &rhs) {
            return lhs[1] < rhs[1];
        });
        int tmp = trips[0][0];
        if (tmp > capacity) {
            return false;
        }
        priority_queue<pair<int, int>, deque<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({trips[0][2], trips[0][0]});
        for (int i = 1; i != trips.size(); ++i) {
            while (!pq.empty() && pq.top().first <= trips[i][1]) {
                auto top = pq.top();
                tmp -= top.second;
                pq.pop();
            }
            tmp += trips[i][0];
            if (tmp > capacity) {
                return false;
            }
            pq.push({trips[i][2], trips[i][0]});
        }
        return true;
    }
};

int main() {
  
  
  
  return 0;  
}
