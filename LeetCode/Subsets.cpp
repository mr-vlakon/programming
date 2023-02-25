class Solution {
public:
    void generate(const vector<int> &num, int i, vector<int> &v) {
        if (i == num.size()) {
            result.push_back(v);
            return;
        }
        v.push_back(num[i]);
        generate(num, i + 1, v);
        v.pop_back();
        generate(num, i + 1, v);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> empty;
        generate(nums, 0, empty);
        return result;
    }
private:
    vector<vector<int>> result;
};

int main() {
  
  
  return 0;  
}
