class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        if (roads.size() == 0) return true;
        unordered_map<int, vector<pair<int, int>>> um;
        for (const auto &e: roads) {
            um[e[0] - 1].push_back({e[1] - 1, e[2]});
            um[e[1] - 1].push_back({e[0] - 1, e[2]});
        }
        int minV = 100000;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            visited[top] = true;
            for (const auto &e: um[top]) {
                if (!visited[e.first]) {
                    q.push(e.first);
                    minV = min(minV, e.second); 
                }
            }
        }
        return minV;
    }
};

int main() {
  
  
  
  return 0;  
}
