class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        for (int i = 0; i != nums.size(); ++i) {
            while (!st.empty()  && (nums[i] < st.top()) 
                && (nums.size()) > (k + i - st.size())) {
                    st.pop();
            }
            st.push(nums[i]);
        }
        vector<int> answer(k);
        int i = k - 1;
        while (!st.empty() && i >= 0) {
            if (st.size() <= k) {
                answer[i] = st.top();
                --i;
            }
            st.pop();
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
