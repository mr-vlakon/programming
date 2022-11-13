class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int answer = 0;
        for (int i = 0; i != nums.size(); ++i) {
            unsigned long long l = nums[i];
            bool flag = true;
            for (int j = i; j != nums.size(); ++j) {
                l = lcm(l, static_cast<unsigned long long>(nums[j]));
                if (l == k) {
                    ++answer;
                    flag = false;
                } else if (flag == false) {          
                    break;
                }
            }
        }    
        return answer;
    } 
};

int main() {
  
  
  
  return 0;  
}
