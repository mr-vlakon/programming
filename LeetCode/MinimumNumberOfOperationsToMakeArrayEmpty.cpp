class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> um;
        for (const auto &e: nums) ++um[e];
        int answer = 0;
        for (const auto &e: um) {
            if ((e.second % 3) == 0) {
               answer += e.second / 3; 
            } else {
                int tmp = e.second % 3;
                if (tmp == 1) {
                    if (e.second / 3 == 0) return -1;
                    answer += (e.second / 3 - 1) + 2;
                } else if (tmp == 2) {
                    answer += e.second / 3 + 1;
                } else {
                    return -1;
                }
            }
        }
        return (answer == 0) ? -1 : answer;
    }
};

int main()
{


  return 0;
}

