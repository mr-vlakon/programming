class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        unordered_map<int, size_t> um;
        for (const auto &e: matches) {
            st1.insert(e[0]);
            st1.insert(e[1]);
            um[e[1]]++;
            st2.insert(e[1]);
        }
        vector<int> answer1;
        for (const auto &e: st1) {
            if (st2.find(e) == st2.cend()) {
                answer1.push_back(e);
            }
        }
        vector<int> answer2;
        for (const auto &e: um) {
            if (e.second == 1)
                answer2.push_back(e.first);
        }
        sort(answer1.begin(), answer1.end());
        sort(answer2.begin(), answer2.end());
        return {answer1, answer2};        
    }
};

int main() {
  
  
  return 0;  
}
