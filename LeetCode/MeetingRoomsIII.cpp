class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](vector<int> &lhs, vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        unordered_map<int, int> um;
        um[0]++;
        int room = 0;
        int max = 1;
        long tmp = meetings[0][1];
        priority_queue<pair<long, int>, deque<pair<long, int>>, greater<pair<long, int>>> pq;
        pq.push({tmp, 0});
        priority_queue<int, deque<int>, greater<int>> pqMin;
        for (int i = 1; i != n; ++i) {
            pqMin.push(i);
        }     
        for (int i = 1; i != meetings.size(); ++i) {
            while (!pq.empty() && pq.top().first <= meetings[i][0]) {
                auto top = pq.top();
                pqMin.push(top.second);
                pq.pop();
            }
            if (pqMin.empty()) {
                auto top = pq.top();
                long start = 0;
                if (top.first > meetings[i][0]) {
                    start = top.first;
                } else {
                    start = meetings[i][0];
                }
                pq.pop();
                um[top.second]++;
                if (um[top.second] > max) {
                    max = um[top.second];
                    room = top.second;
                } else if (um[top.second] == max) {
                    if (top.second < room) {
                        room = top.second;
                    }
                }               
                pq.push({start + (meetings[i][1] - meetings[i][0]), top.second});
            } else {
                auto top = pqMin.top();
                pqMin.pop();
                um[top]++;
                if (um[top] > max) {
                    max = um[top];
                    room = top;
                } else if (um[top] == max) {
                    if (top < room) {
                        room = top;
                    }
                }
                pq.push({meetings[i][1], top});
            }           
        }
        return room;
    }
};

int main() {
  
    
  return 0;  
}
