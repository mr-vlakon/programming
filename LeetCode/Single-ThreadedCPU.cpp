class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i != tasks.size(); ++i) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(), [](vector<int> &lhs, vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        priority_queue<pair<int, int>, deque<pair<int, int>>, greater<pair<int, int>> > pq;
        int maxV = tasks[0][0];
        int i = 0;
        while (i != tasks.size() && tasks[i][0] == maxV) {
            pq.push({tasks[i][1], tasks[i][2]});
            ++i;
        }
        int maxTime = tasks.back()[0];
        vector<int> answer;
        pair<int, int> top;
        int t = 0;
        while (!pq.empty() && i < tasks.size()) {
            top = pq.top();
            pq.pop();
            answer.push_back(top.second);
            maxV = min(maxTime, maxV + top.first);
            while (i < tasks.size() && tasks[i][0] <= maxV) {
                pq.push({tasks[i][1], tasks[i][2]});
                ++i;
            }
            if (pq.empty() && i < tasks.size()) {
                t = tasks[i][0];
                maxV = min(maxTime, maxV + tasks[i][0]);
                while (i != tasks.size() && t >= tasks[i][0]) {
                    pq.push({tasks[i][1], tasks[i][2]});
                    ++i;
                }
            }
        }
        while (!pq.empty()) {
            top = pq.top();
            answer.push_back(top.second);
            pq.pop();
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
