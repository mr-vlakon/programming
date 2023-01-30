/*
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> m;
        for (const auto &e: nums) {
            m[e]++;
        }
        int answer = 0;
        int size = m.size();
        auto it = --m.end();
        while (it != m.begin()) {
            answer += (it->second) * (size - 1);
            --size;
            --it;
        }
        return answer;
    }
};
*/

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        auto it = nums.cbegin();
        auto prev = nums.cbegin();
        int size = 0;
        int answer = 0;
        int min = nums[nums.size() - 1];
        while (*it != min) {
            prev = it;
            it = find_if(it, nums.cend(), [&](const int &x) {
                return x != *it;
            });
            size += it - prev;
            answer += size;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
