class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 0;
        for (auto &e: nums) {
            int index = 0;
            while (e) {
                if (e % 2 == 1 && st.find(index) == st.cend()) {
                    ans += pow(2, index);
                    st.insert(index);
                }
                e /= 2;
                ++index;
            }
        }
        return ans;
    }
};

int main() {
  
  
  return 0;  
}
