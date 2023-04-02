class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> um;
        for (const auto &e: nums) {
            ++um[e];
        }
        int maxC = 0;
        for (const auto &e: um) {
            if (e.second > maxC) {
                maxC = e.second;
            }
        }
        vector<vector<int>> answer(maxC);
        for (int i = 0; i != answer.size(); ++i) {
            for (auto &e: um) {
                if (e.second > 0) {
                    answer[i].push_back(e.first);
                    --e.second;
                }
            }
        }
        return answer;     
    }
};

int main() {
  
  
  
  
  return 0;  
}
