class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int answer = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if ((nums.size() % (i + 1)) == 0) {
                answer += nums[i]*nums[i];
            }
        }
        return answer;
    }
};

int main() {


  return 0;
}
