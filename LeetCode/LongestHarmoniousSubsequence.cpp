class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int ,int> m;
        for (const auto &e: nums) {
            ++m[e];
        }
        int prev = m.cbegin()->first;
        int prevs = m.cbegin()->second;
        bool status = true;
        int answer = 0;
        for (const auto &e: m) {
            if (status) {
                status = false;
                continue;
            } else {
                if (e.first - prev == 1) {
                    if (prevs + e.second > answer)
                        answer = prevs + e.second;
                }
                
            }
            prev = e.first;
            prevs = e.second;
            
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
