class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int answer = 0;
        for (int i = 0; i != nums.size(); ++i) {
            for (int j = i; j != nums.size(); ++j) {
                vector<int> left(nums.cbegin(), nums.cbegin() + i);
                vector<int> right(nums.cbegin() + j + 1, nums.cend());
                int tmp = 0;
                if (left.size() != 0) {
                    tmp = left[0];
                }
                bool flag = true;
                for (int k = 1; k < left.size(); ++k) {
                    if (left[k] > left[k - 1]) {
                        
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                    tmp = left[k];
                }
                if (!flag) continue;
                for (int k = 0; k != right.size(); ++k) {
                    if (right[k] > tmp) {
                        
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                    tmp = right[k];
                }
                if (flag == true) ++answer;
            }
        }
        return answer;
    }
};

int main()
{

  return 0;
}
