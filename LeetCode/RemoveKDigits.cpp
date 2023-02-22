class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int cnt = 0;
        for (int i = 0; i != num.size(); ++i) {
            if (!st.empty() && cnt < k && num[i] < st.top()) {
                while (!st.empty() && cnt < k && (num[i] < st.top())) {
                    st.pop();
                    ++cnt;
                }
            } 
            if (st.empty() && num[i] == '0') {

            } else {
                st.push(num[i]);
            }
        }
        string answer;
        while (!st.empty()) {
            if (cnt >= k) {
                answer.push_back(st.top());
            }
            ++cnt;
            st.pop();
        }
        if (answer.size() == 0) {
            return "0";
        }
        return {answer.rbegin(), answer.rend()};
    }
};

int main() {
  
  
  
  return 0;  
}
