class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        vector<priority_queue<int>> v(nums.size());
        int i = 0;
        for (const auto &e: nums) {
            for (const auto &p: e) {
                v[i].push(p);
            }
            ++i;
        }
        i = 0;
        int answer = 0;
        int maxV = 0;
        while (i < nums[0].size()) {
            maxV = 0;
            for (auto &e: v) {
                maxV = max(e.top(), maxV);
                e.pop();
            }
            
            answer += maxV;    
            ++i;
        }
        return answer;
        
    }
};

int main() {
  
  
  
  return 0;  
}
