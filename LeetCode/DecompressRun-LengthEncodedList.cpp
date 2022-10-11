class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        int i = 0;
        while (2*i + 1 < nums.size()) {
            int freq = nums[2*i];
            int val = nums[2*i + 1];
            while (freq) {
                res.push_back(val);
                --freq;
            }
            ++i;
        }
        return res;
    }
};

int main() {
  
  
  return 0;  
}
