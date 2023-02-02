class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> um;
        int i = 1;
        for (const auto &e: isConnected) {
            int j = 1;
            for (const auto &p: e) {
                if (p == 1 && i != j) {
                    um[i].push_back(j);
                }
                ++j;
            }
            ++i;
        }
        i = 1;
        queue<int> q;
        int cnt = 0;
        unordered_set<int> us;
        while (i <= isConnected.size()) {
            if (us.find(i) != us.cend()) {
                ++i;
                continue;
            }
            ++cnt;
            q.push(i);
            us.insert(i);
            while(!q.empty()) {
                auto top = q.front();
                q.pop();
                for (const auto &e: um[top]) {
                    if ((us.find(e) == us.cend())) {    
                        us.insert(e);
                        q.push(e);
                    }
                }   
            }
            ++i;
        }
        return cnt; 
    }
};

int main() {
  
  
  return 0;  
}
