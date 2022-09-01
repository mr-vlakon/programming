class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(),[](const string &lhs, const string &rhs){
          return lhs > rhs; 
       });
        stable_sort(nums.begin(), nums.end(),[](const string &lhs, const string &rhs){
          return lhs.size() > rhs.size(); 
       });
       return *(nums.cbegin() + k - 1); 
    }
};

int main() {
  
  return 0;  
}
