class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        reverse(nums.begin(), nums.end());
        for (auto &e: nums) {
            while (e) {
                result.push_back(e % 10);
                e /= 10;
            }            
        }
        reverse(result.begin(), result.end());  
        return result;
    }
};

int main() {
  
  
  return 0;  
}
