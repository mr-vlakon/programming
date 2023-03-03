class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        queue<int> q;
        unordered_map<int, vector<int>> um;
        for (const auto &e: edges) {
            um[e[0]].push_back(e[1]);
            um[e[1]].push_back(e[0]);  
        }
        int top = 0;
        int cnt = 0;
        for (int i = (edges.size() - 1); i >= 0; --i) {
            if (um[edges[i][0]].size() < 2) {
                continue;
            }
            vector<bool> visited(edges.size() + 1, false);            
            q.push(1);
            cnt = 1;
            while (!q.empty()) {
                top = q.front();
                q.pop();
                visited[top] = true;
                for (const auto &e: um[top]) {
                    if (visited[e] == false) {
                        if (top == edges[i][0] && e == edges[i][1]) {
                            continue;
                        }
                        if (top == edges[i][1] && e == edges[i][0]) {
                            continue;
                        }                        
                        visited[e] = true;
                        ++cnt;
                        q.push(e);
                    }
                }
            }
            if (cnt == edges.size()) {
                return edges[i];
            }
        }
        return {};
    }
};

int main() {
  
  
  
  return 0;  
}
