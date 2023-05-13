class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto &e: nums) {
            sort(e.begin(), e.end());
        }
        int answer = 0;
        int maxV = 0;
        for (int j = 0; j != nums[0].size(); ++j) {
            maxV = 0;
            for (int i = 0; i != nums.size(); ++i) {
                maxV = max(nums[i][j], maxV);
            }
            answer += maxV;
        }
        return answer;
    }
};
/*
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
*/

int main() {
  
  
  
  return 0;  
}
