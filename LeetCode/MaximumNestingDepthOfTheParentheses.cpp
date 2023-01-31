class Solution {
public:
    int maxDepth(string s) {
        int answer = 0;
        int cnt = 0;
        stack<char> st;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == '(') {
                st.push(s[i]);
                ++cnt;         
            } else if (s[i] == ')') {
                if (cnt > answer) {
                    answer = cnt;
                }
                while (st.size() != 0 && st.top() != '(') {
                    st.pop();
                }
                if (st.size() != 0) {
                    --cnt;
                    st.pop();
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
