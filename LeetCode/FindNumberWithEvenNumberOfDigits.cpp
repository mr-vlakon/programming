class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(const auto &e: nums ) {
           if (to_string(e).length() % 2 == 0)
               ++result;
       } 
       return result; 
    }
};

int main() {
  
  return 0; 
}
