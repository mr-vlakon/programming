class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        auto beg = find(nums.cbegin(), nums.cend(), 0);
        long long cnt = 0;
        while (beg != nums.cend()) {
            auto end = find_if(beg, nums.cend(),[=](const int &x) {
               return x != 0; 
            });
            int size = end - beg;
            while(size) {
                cnt += size;
                --size;
            }
            beg = find(end, nums.cend(), 0);
        }       
        return cnt;
    }
};

int main() {
  
  return 0;  
}
