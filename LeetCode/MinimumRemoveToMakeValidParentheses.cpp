class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cntL = 0;
        int cntR = 0;
        stack<int> st;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
                cntL++;
            } else if (s[i] == ')' && cntR < cntL) {
                st.pop();
                --cntL;
            } else if (s[i] == ')') {
                st.push(i);
            } 
        }
        string answer(static_cast<int>(s.size() - st.size()), '0');
        int j = answer.size() - 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (!st.empty() && st.top() == i) {
                st.pop();
            } else {
                answer[j] = s[i];
                --j;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
