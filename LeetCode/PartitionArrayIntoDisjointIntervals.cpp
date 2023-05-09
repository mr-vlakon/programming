class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int maxV = nums[0];
        int val = nums[0];
        int answer = 1;
        for (int i = 1; i != nums.size(); ++i) {
            if (maxV > nums[i]) {
                maxV = val;    
                answer = i + 1;
            } 
            val = max(val, nums[i]);     
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
