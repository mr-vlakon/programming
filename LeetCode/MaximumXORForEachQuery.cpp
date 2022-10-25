class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> answer;
        int prefix = 0;
        int x = pow(2, maximumBit) - 1;
        for (const auto &e: nums) {
            prefix ^= e;
            answer.push_back(prefix ^ x);
        }    
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
