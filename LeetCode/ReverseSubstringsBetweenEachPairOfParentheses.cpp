class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        deque<char> second;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '(' && s[i] != ')') {
                st.push(s[i]);
            } else if (s[i] == '(') {
                st.push(s[i]);
            } else {
                while (st.top() != '(') {
                    second.push_back(st.top());
                    st.pop();
                }
                st.pop();
                while (!second.empty()) {
                    st.push(second.front());
                    second.pop_front();
                }
            }
        }
        string answer(st.size(), ' ');
        int pos = st.size() - 1;
        while (!st.empty()) {
            answer[pos] = st.top();
            --pos;
            st.pop();
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
