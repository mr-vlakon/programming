class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> index;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == key) {
                index.push_back(i);
            }
        }
        
        vector<int> answer;
        for (int i = 0; i != nums.size(); ++i) {
            for (const auto &e: index) {
                if (abs(e - i) <= k) {
                    answer.push_back(i);
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
