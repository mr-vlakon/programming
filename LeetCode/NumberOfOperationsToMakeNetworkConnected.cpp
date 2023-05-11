class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if ((n - 1) > connections.size()) return -1;
        unordered_map<int, vector<int>> um;
        for (const auto &e: connections) {
            um[e[0]].push_back(e[1]);
            um[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        int cnt = 0;
        int answer = -1;
        int top = 0;
        for (int i = 0; i != visited.size(); ++i) {
            if (visited[i] == false) {
                ++answer;
                q.push(i);
                while(!q.empty()) {
                    top = q.front();
                    q.pop();
                    visited[top] = true;
                    for (const auto &e: um[top]) {
                        if (!visited[e]) {    
                            visited[e] = true;
                            q.push(e);
                        }
                    }
                }
            }
        }
        return answer;        
    }
};

int main() {
  
  
  
  return 0;  
}
