class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for_each(nums.cbegin(), nums.cend(), [&] (const int &x) {
           if (x % 2 == 0)
               sum += x;
        });
        vector<int> answer;
        for (const auto &e: queries) {
            nums[e[1]] += e[0];
            if ( nums[e[1]] % 2 == 0 && ((nums[e[1]] - e[0]) % 2 != 0) ) {
                sum += nums[e[1]];
            } else if (nums[e[1]] % 2 == 0 && ((nums[e[1]] - e[0]) % 2 == 0)){
                sum += e[0];
            } else if (nums[e[1]] % 2 != 0 && ((nums[e[1]] - e[0]) % 2 == 0)) {
                sum -= (nums[e[1]] - e[0]);
            }
            answer.push_back(sum); 
        }        
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
