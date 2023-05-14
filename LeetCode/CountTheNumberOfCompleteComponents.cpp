class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        for (const auto &e: edges) {
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }
        queue<int> q;
        vector<bool> visited(n, 0);
        int answer = 0;
        int cnt = 0;
        int counter = 0;
        for (int i = 0; i != n; ++i) {
            if (visited[i] == false) {
                cnt = v[i].size();
                counter = 1;
                visited[i] = true;
                q.push(i);
                while (!q.empty()) {
                    auto top = q.front();
                    visited[i] = true;
                    q.pop();
                    for (const auto &e: v[top]) {
                        if (!visited[e]) {
                            visited[e] = true;
                            q.push(e);
                            cnt += v[e].size();
                            ++counter;
                        }
                    }
                }
                if (cnt == (counter*(counter - 1))) {
                    ++answer;
                }
            }          
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
