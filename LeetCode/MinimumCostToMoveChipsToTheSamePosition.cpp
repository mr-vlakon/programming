class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        unordered_map<int, int> um;
        for (const auto &e: position) {
            ++um[e];
        }
        int answer = 1000000;
        for (const auto &e: um) {
            int tmp = 0;
            for (const auto &p: um) {
                if (e.first != p.first) {
                    if ((abs(e.first - p.first) % 2) == 1) {
                        tmp += p.second;
                    }
                }
            }
            answer = min(answer, tmp);
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
