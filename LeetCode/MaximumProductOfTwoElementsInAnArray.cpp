class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        auto it = max_element(nums.cbegin(), nums.cend());
        int first = *it - 1;
        nums.erase(it);
        it = max_element(nums.cbegin(), nums.cend());
        int second = *it - 1;
        return first * second;
    }
};

int main() {
  
  
  return 0;  
}
