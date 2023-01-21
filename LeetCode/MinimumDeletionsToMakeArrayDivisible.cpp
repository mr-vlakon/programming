/*
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        vector<int> temp(nums);
        auto p = unique(nums.begin(), nums.end());
        nums.erase(p, nums.end());
        int index = 0;
        bool status = true;
        sort(numsDivide.begin(), numsDivide.end());
        p = unique(numsDivide.begin(), numsDivide.end());
        numsDivide.erase(p, numsDivide.end());
        for (const auto &p : nums) {
            status = true;
            for (const auto &e : numsDivide) {
                if (e % p != 0) {
                    status = false;
                    break;
                }
            }
            if(status) {
                break;
            }
            ++index;
        }
        if (index != nums.size()) {
            auto it = find(temp.cbegin(), temp.cend(), nums[index]);
            auto otvet = it - temp.cbegin();
            return otvet;
        } else
            return -1;
    }
};
*/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        auto gcd_ = numsDivide[0];
        for (int i = 1; i != numsDivide.size(); ++i) {
            gcd_ = gcd(gcd_, numsDivide[i]);
        }
        sort(nums.begin(), nums.end());
        auto start = nums.begin();
        auto prev = start;
        int answer = 0;
        while (start != nums.end()) {
            if (gcd_ % *start == 0) {
                return answer;
            } else {
                prev = start;
                start = find_if(start + 1, nums.end(), [&](const int &x) {
                    return x != *start;
                });
                answer += start - prev;
            }
        }
        return -1;
    }
};



int main() {

  return 0;  
}
