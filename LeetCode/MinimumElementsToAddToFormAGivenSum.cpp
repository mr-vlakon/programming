class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        double sum = accumulate(nums.cbegin(), nums.cend(), 0.0);
        return (abs(goal - sum) + limit - 1) / limit;
    }
};

int main() {
  
  
  return 0;  
}
