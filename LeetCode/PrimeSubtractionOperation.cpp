class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int start = 0;
        int findV = 0;
        for (int i = 0; i != nums.size(); ++i) {
            start = nums[i];
            findV = 0;
            if (((i - 1) >= 0 && nums[i] > nums[i - 1]) || (i == 0 && nums[i] != 1))  {
                start = nums[i] - 1;
                while (start) {
                    if ((start % 2) == 0 && (start != 2)) {
                        --start;
                    } else if ((start % 3) == 0 && (start != 3)) {
                        --start;
                    } else if ((start % 5) == 0 && (start != 5)) {
                        --start;
                    } else if ((start % 7) == 0 && (start != 7)) {
                        --start;
                    } else if (i == 0 || ((i - 1) >= 0 && (nums[i] - start) > nums[i - 1])) {
                        findV = start;
                        break;
                    } else  {
                        --start;
                    }
                }
                if (findV != 1 && findV != nums[i]) {
                    nums[i] -= findV;
                } 
            }
        }
        for (int i = 0; i != nums.size() -1; ++i) {
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
  
  
  return 0;  
}
