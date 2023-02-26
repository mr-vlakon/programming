class Solution {
public:
    void generate(const vector<int> &num, int i, vector<int> &v, int &target) {
        if (target > tar) {
            return;
        }
        if (i > num.size()) {
            return;
        }
        if (i == num.size()) {
            if (target == tar) {
                result.push_back(v);
            }
            return;
        } 
        int tmp = (v.size() != 0) ? v.back() : 0;
        v.push_back(num[i]);
        target += num[i];
        if (target <= tar) {
            generate(num, i + 1, v, target);
        }
        target -= v.back();     
        v.pop_back();
        if (target <= tar && num[i] != tmp) {
            generate(num, i + 1, v, target);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        tar = target;
        vector<int> empty;
        sort(candidates.begin(), candidates.end());
        int x = 0;
        generate(candidates, 0, empty, x);
        return result;
    }
private:
    int tar = 0;
    vector<vector<int>> result;
};

int main() {
  
  
  
  return 0;  
}
