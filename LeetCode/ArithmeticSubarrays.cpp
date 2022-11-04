class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> answer;
        for (decltype(l.size()) i = 0; i != l.size(); ++i) {
            vector<int> v(nums.cbegin() + l[i], nums.cbegin() + r[i] + 1);
            sort(v.begin(), v.end());
            if (v.size() == 1) {
                answer.push_back(true);
                continue;
            }
            auto tmp = v[1] - v[0];

            bool status = true;
            for (decltype(v.size()) j = 2; j != v.size(); ++j) {
                if (tmp != (v[j] - v[j - 1])) {
                    status = false;
                    break;
                }
            }
            if (status) {
                answer.push_back(true);
            } else {
                answer.push_back(false);
            }
            
        }
        return answer;
        
    }
};

int main() {
  
  
  
  return 0;  
}
