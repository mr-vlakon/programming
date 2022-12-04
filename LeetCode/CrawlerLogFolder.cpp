class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for (const auto &e: logs) {
            if (e == "../" && !st.empty()) {
                st.pop();
            } else if (e != "./" && e != "../") {
                st.push(e);
            }
        }
        return st.size();
    }
};

int main() {
  
  
  return 0;  
}
