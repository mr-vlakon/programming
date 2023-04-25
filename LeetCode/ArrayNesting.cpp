class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        int cnt = 0;
        int answer = 0;
        stack<int> st;
        int top = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (visited[i] == false) {
                st.push(nums[i]);
                cnt = 0;
                while (!st.empty()) {
                    top = st.top();
                    st.pop();
                    visited[top] = true;
                    ++cnt;
                    if (!visited[nums[top]]) {
                        st.push(nums[top]);
                    }
                }
                answer = max(answer, cnt);
            }
        }
        return answer; 
    }
};

int main() {
  
  
  
  
  return 0;  
}
