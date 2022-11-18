class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>> > pq;
        
        for (const auto &e: classes) {
            double newRatio = static_cast<double>(e[0] + 1) / static_cast<double>(e[1] + 1);
            double oldRatio = static_cast<double>(e[0]) / static_cast<double>(e[1]);
            double change = newRatio - oldRatio;
            pq.push({change,{e[0], e[1]}});
        }
        
        int i = 0;
        while (i != extraStudents) {
            auto top = pq.top();
            pq.pop();
            double newRatio = static_cast<double>(top.second.first + 2) / static_cast<double>(top.second.second + 2);
            double oldRatio = static_cast<double>(top.second.first + 1) / static_cast<double>(top.second.second + 1);
            double change = newRatio - oldRatio;
            pq.push({change,{top.second.first + 1, top.second.second + 1}});
            ++i;
        }
        double answer = 0.00;
        int cnt = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            answer += static_cast<double>(top.second.first) / static_cast<double>(top.second.second);
            ++cnt;
            pq.pop();
        }
        return answer / cnt;
        
    }
};

int main() {
  
  
  
  return 0;  
}
