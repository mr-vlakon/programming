class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> temp = nums;
        int index = 0;
        if(is_sorted(nums.begin(), nums.end())) return true;
        while (index != nums.size()) {
            rotate(temp.begin(), temp.begin() + 1, temp.end());
            if (is_sorted(temp.begin(), temp.end()))
                return true;
            ++index;
        } 
        return false;
        
    }
};

int main() {

  return 0;
}
