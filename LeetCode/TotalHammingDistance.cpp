class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bits(32, 0);
        int k = 0;
        for (const auto &e: nums) {
            k = 0;
            while (e >= (1 << k)) {
                if ((e & (1 << k)) != 0) {
                    bits[k]++;
                }
                ++k;
            }
        }
        int ans = 0;
        for (int i = 0; i != bits.size(); ++i) {
            ans += bits[i] * (nums.size() - bits[i]);
        }
        return ans;
    }
};

int main() {
  
  
  
  return 0;  
}
