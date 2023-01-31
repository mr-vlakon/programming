class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string answer;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == '(' && (st.size() == 0)) {
                st.push(s[i]);
            } else if (s[i] == '('){
                ++cnt1;
                answer.push_back(s[i]);
            } else if (s[i] == ')' && (cnt1 != cnt2)) {
                ++cnt2;
                answer.push_back(s[i]);
            } else if ((cnt1 == cnt2) && (s[i] == ')')) {
                st.pop();
            }
        }

        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
