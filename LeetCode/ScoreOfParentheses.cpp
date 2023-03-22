class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int answer = 0;        
        st.push(-1);
        st.push(1);
        int x = 0;
        int siz = 0;
        int cnt = 1;
        int t = 0;
        for (int i = 1; i != s.size() - 1; ++i) {
            if (s[i] == '(' && s[i - 1] == '(') {
                if (st.top() != -1 && st.top() != -2)
                    x = st.top();
                else {
                    t = st.top();
                    st.pop();
                    x = st.top();
                    st.push(t);
                }
                ++cnt;
                st.pop();
                st.push(-1);
                st.push(x * 2);            
            } if (s[i] == '(' && s[i - 1] == ')') {
                siz = cnt;
                ++cnt;                
                st.push(-1);
                st.push(pow(2, siz));
            } else if (s[i] == ')'){
                if (st.top() != -1 && st.top() != -2)
                    x = st.top();
                else {
                    t = st.top();
                    st.pop();
                    x = st.top();
                    st.push(t);
                }
                --cnt;
                st.pop();
                st.pop();
                st.push(x);
                st.push(-2);
            }
        }

        while (!st.empty()) {
            if (st.top() != -1 && st.top() != -2) {
                answer += st.top();
            }
            st.pop();
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
