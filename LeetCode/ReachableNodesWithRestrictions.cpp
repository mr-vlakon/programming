class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        queue<int> q;
        unordered_set<int> us;
        unordered_set<int> rest;
        unordered_map<int, vector<int>> um;
        for (const auto &e: restricted) {
            rest.insert(e);
        }
        for (const auto &e: edges) {
            um[e[0]].push_back(e[1]);
            um[e[1]].push_back(e[0]);
        }
        q.push(0);
        us.insert(0);
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            for (const auto &e: um[top]) {
                if ((us.find(e) == us.cend()) && (rest.find(e) == rest.cend())) {    
                    us.insert(e);
                    q.push(e);
                }
            }
        }
        return us.size(); 
    }
};

int main() {
  
  
  
  return 0;  
}
