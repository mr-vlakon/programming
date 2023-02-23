class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> answer;
        int start = 0;
        for (int i = 0; i != nums.size(); ++i) {
            ++start;
            while((nums[i] - start) >= 1) {
                answer.push_back(start);
                ++start;
            } 
            start = nums[i];
        }
        ++start;
        while (start <= nums.size()) {
            answer.push_back(start);
            ++start;
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
