class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> us;
        for (int i = 0; i != nums.size(); ++i) {
            us.insert(nums[i]);
        }
        int pos = -1;
        for (int i = 0; i != 32; ++i) {
            if (us.find(pow(2, i)) == us.cend()) {
                pos = i;
                break;
            }
        }
        return pow(2, pos);
    }
};

int main() {
  
  
  reutrn 0;  
}
