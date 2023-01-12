class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int answer = 0;
        int prev = 0;
        bool status = false;
        for (int i = 0; i != nums.size(); ++i) {       
                bool hill = false;
                bool valley = false;
                for (int j = i - 1; j >= 0; --j) {
                    if (nums[j] > nums[i]) {
                        status = true;
                        valley = true;
                        break;
                    } else if (nums[j] < nums[i]) {
                        status = true;
                        hill = true;
                        break;
                    }
                }
                bool st = false;
                if (status) {
                    for (int j = i + 1; j < nums.size(); ++j) {
                        if (valley) {
                            if (nums[j] > nums[i]) {
                                st = true;
                                break;
                            } else if (nums[j] < nums[i]) {
                                break;
                            }
                        } else if (hill) {
                           if (nums[j] < nums[i]) {
                                st = true;
                                break;
                            } else if (nums[j] > nums[i]) {
                                break;
                            }
 
                        }
                    }
                }
                if (st && status && (prev != nums[i])) {
                    ++answer;
                }
                prev = nums[i];
                status = false;
       }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
