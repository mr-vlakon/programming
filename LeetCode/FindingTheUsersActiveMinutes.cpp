class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> um;
        for (const auto &e: logs) {
            um[e[0]].insert(e[1]);
        } 
        vector<int> answer(k, 0);
        unordered_map<int, int> un;
        for (const auto &e: um) {
            un[e.second.size()]++;
        }
        for (const auto &e: un) {
            answer[e.first - 1] = e.second;
        }
        return answer;   
    }
};

int main() {
  
  
  return 0;  
}
