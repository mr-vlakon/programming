class Solution {
public:
    int findMin(vector<int>& nums) {
        set<int> st;
        for (const auto &e: nums) {
            st.insert(e);
        }     
        auto it = st.begin();
        return *it;   
    }
};

int main() {
  
  return 0;
}
