class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        if (heights.size() == 1) return {0};
        vector<int> answer(heights.size(), 0);
        stack<int> st;
        st.push(heights.back());
        for (int i = static_cast<int>(heights.size()) - 2; i >= 0; --i) {
            if (heights[i] > st.top()) {
                int tmp = 0;
                while (!st.empty() && st.top() <= heights[i]) {
                    auto top = st.top();
                    st.pop();
                    ++tmp;
                }
                if (!st.empty() && st.top() > heights[i]) {
                    ++tmp;
                }
                st.push(heights[i]);
                answer[i] = tmp;
            } else {
                int tmp = 0;
                st.push(heights[i]);
                ++tmp;
                answer[i] = tmp;
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
