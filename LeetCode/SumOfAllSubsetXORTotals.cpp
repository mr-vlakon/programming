class Solution {
public:
    void generate(const vector<int> &num, int i, int &currXor) {
        if (i == num.size()) {
            answer += currXor;
            return;
        }
        int tmp = currXor;
        currXor ^= num[i];
        generate(num, i + 1, currXor);
        generate(num, i + 1, tmp);
    }
    int subsetXORSum(vector<int>& nums) {
        int x = 0;
        generate(nums, 0, x);
        return answer;
    }
private:
    int answer = 0;
};

int main() {
  
  
  return 0;  
}
