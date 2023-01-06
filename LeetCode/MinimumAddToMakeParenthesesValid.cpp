class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        st.push(s[0]);
        int cnt = 0;
        for (int i = 1; i != s.size(); ++i) {
            if (s[i] == ')') {
                if (st.empty()) {
                    ++cnt;
                } else if (st.top() == '(') {
                    st.pop();
                } else if (st.top() == ')') {
                    st.push(s[i]);
                }
            } else {
                st.push(s[i]);
            }
        }
        return cnt + st.size();
    }
};

int main() {
  
  
  
  return 0;  
}
