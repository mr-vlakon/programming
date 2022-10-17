class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, size_t> um;
        for (const auto &e: roads) {
            ++um[e[0]];
            ++um[e[1]];
        }
        priority_queue<pair<size_t, int>> pq;
        for (const auto &e: um) {
            pq.push({e.second, e.first});
        }
        long long answer = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            answer += top.first * n;
            pq.pop();
            --n;
        }
        
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
