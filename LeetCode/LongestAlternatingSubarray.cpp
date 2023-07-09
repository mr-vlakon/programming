class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int answer = 0;
        int start = 1;
        bool status = false;
        for (int i = 0; i != nums.size(); ++i) {
            start = 1;
            status = false;
            for (int j = i; j != nums.size() - 1; ++j) {
                if ((nums[j + 1] - nums[j]) != 1*start) {
                    status = true;
                    if ((j - i + 1) > 1) {
                        answer = max(answer, j - i + 1);
                    }
                    break;
                }
                start = -start;
            }
            if (!status) {
                if ((nums.size() - i) > 1) {
                    answer = max(answer, static_cast<int>(nums.size()) - i);
                }
            }
        }
        if (answer == 0) return -1;     
        return answer;
    }
};

int main() {

  
  return 0;
}
