class Solution {
public:
    void generate(vector<int> num, int index = -1,
                    vector<int> curr = {}) {
        if (index == num.size())
            return;

        if (!curr.empty()) {
            v.push_back(curr);
        }

        for (int i = index + 1; i < num.size(); i++) {
            curr.push_back(num[i]);
            generate(num, i, curr);
            curr.pop_back();
        }
        
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        generate(nums);
        int sum = 0;
        for (const auto &e: v) {
            int tmp = 0;
            for (const auto &p: e) {
                tmp ^= p;
            }
            sum += tmp;
        }
        
        return sum;
    }
private:
    vector<vector<int>> v;
};

int main() {
  
  
  return 0;  
}
