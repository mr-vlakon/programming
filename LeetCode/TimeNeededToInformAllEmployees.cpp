class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> um(n);
        for (int i = 0; i != manager.size(); ++i) {
            if (manager[i] != -1) {
                um[manager[i]].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        visited[headID] = true;
        q.push({headID, 0});
        int answer = 0;
        pair<int, int> top;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            answer = max(answer, top.second);
            visited[top.first] = true;
            for (const auto &e: um[top.first]) {
                if (!visited[e]) {
                    visited[e] = true;
                    q.push({e, top.second + informTime[top.first]});
                }
            } 
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
