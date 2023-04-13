class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>, deque<pair<int, int>>, greater<pair<int, int>>> pqMin;
        priority_queue<pair<int, int>, deque<pair<int, int>>, less<pair<int, int>>> pqMax;
        int tmp = 0;
        pair<int, int> top;
        for (int i = 0; i != orders.size(); ++i) {
            if (orders[i][2] == 0) {
                while (!pqMin.empty() && pqMin.top().first <= orders[i][0] && orders[i][1] != 0) {
                    top = pqMin.top();
                    pqMin.pop();
                    tmp = min(orders[i][1], top.second);
                    orders[i][1] -= tmp;
                    top.second -= tmp;
                    if (top.second > 0) {
                        pqMin.push(top);
                    } 
                }
                if (orders[i][1] != 0) {
                    pqMax.push({orders[i][0], orders[i][1]});
                }
            } else {
                while (!pqMax.empty() && pqMax.top().first >= orders[i][0] && orders[i][1] != 0) {
                    top = pqMax.top();
                    pqMax.pop();
                    tmp = min(orders[i][1], top.second);
                    orders[i][1] -= tmp;
                    top.second -= tmp;
                    if (top.second > 0) {
                        pqMax.push(top);
                    } 
                }
                if (orders[i][1] != 0) {
                    pqMin.push({orders[i][0], orders[i][1]});
                }
            }
        }
        int answer = 0;
        while (!pqMin.empty()) {
            answer += pqMin.top().second;
            answer %= 1000000007;
            pqMin.pop();
        }
        while (!pqMax.empty()) {
            answer += pqMax.top().second;
            answer %= 1000000007;
            pqMax.pop();
        }     
        return (answer);
    }
};

int main() {
  
  
  
  return 0;  
}
