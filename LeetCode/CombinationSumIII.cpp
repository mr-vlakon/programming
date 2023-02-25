class Solution {
public:
    void generate(const vector<int> &num, int i, vector<int> &v, int &target) {
        if (target > tar) {
            return;
        }
        if (i >= num.size()) {
            if (target == tar && k_ == v.size()) {
                result.push_back(v);
            }
            return;
        } 
        v.push_back(num[i]);
        target += num[i];
        if (target <= tar)
            generate(num, i + 1, v, target);
        target -= v.back();     
        v.pop_back();
        if (target <= tar)
            generate(num, i + 1, v, target);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        tar = n;
        vector<int> empty;
        vector<int> candidates;
        k_ = k;
        int i = 1;
        while (i <= 9) {
            candidates.push_back(i);
            ++i;
        }
        int x = 0;
        generate(candidates, 0, empty, x);
        return result;
    }
private:
    int k_ = 0;
    int tar = 0;
    vector<vector<int>> result;
};

int main() {
  
  
  return 0;  
}
