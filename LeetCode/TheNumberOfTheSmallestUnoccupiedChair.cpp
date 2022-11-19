class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> find = times[targetFriend];
        sort(times.begin(), times.end(), [=](const vector<int> &lhs,
                                             const vector<int> &rhs) {
            return lhs[0] < rhs[0]; 
        });
        priority_queue<int, deque<int>, greater<int> > available;  
        priority_queue<pair<int,int>, deque<pair<int,int>>, greater<pair<int,int>>> pq;
        int j = 0;
        while (j != 10000) {
            available.push(j);
            ++j;
        }
        int answer = 0;
        for (const auto &e: times) {
            if (pq.size() == 0) {
                int top = available.top();
                pq.push({e[1], top});
                available.pop();
            } else {
                while (pq.size() != 0) {
                    auto top = pq.top();
                    if (e[0] >= top.first) {
                        pq.pop();
                        available.push(top.second);
                    } else {
                        break;
                    }
                }
                answer = available.top();
                available.pop();
                pq.push({e[1], answer});
            }
            if (find == e) {
                return answer;
            }
        }
        return 0;
    }
};

int main() {
  
  
  
  return 0;  
}
