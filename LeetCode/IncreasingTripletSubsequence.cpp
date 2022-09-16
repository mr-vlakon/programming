class Solution {
public:
    bool lis(const vector<int> & arr) {
        vector<int> lis(arr.size());
        lis[0] = 1;
        set<int> st(arr.cbegin(), arr.cend());
        if (st.size() < 3) return false;
        for (decltype(arr.size()) i = 1; i < arr.size(); ++i) {
            lis[i] = 1;
            for (decltype(arr.size()) j = 0; j < i; j++) {
                if ((arr[i] > arr[j]) && (lis[i] < lis[j] + 1)) {
                        lis[i] = lis[j] + 1;
                        if (lis[i] >= 3)
                            return true;
                }
            }
        }
        return false;
    }
    bool increasingTriplet(vector<int>& nums) {
        return lis(nums);
    }
};

int main() {
  
  return 0;  
}
