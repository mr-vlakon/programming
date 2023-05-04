class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> um;
        int tmp = 0;
        for (const auto &e: wall) {
            tmp = 0;
            for (int i = 0; i != e.size() - 1; ++i) {
                tmp += e[i];
                um[tmp]++;
            }
        }
        int answer = 0;
        for (const auto &e: um) {
            answer = max(answer, e.second);
        }
        return wall.size() - answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
