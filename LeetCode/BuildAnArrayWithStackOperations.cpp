class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> answer;
        stack<int> st;
        int i = 1;
        int j = 0;
        while (j < target.size()) {
            if (target[j] == i) {
                ++j;
                answer.push_back("Push");
            } else {
                st.push(target[j]);
                answer.push_back("Push");
                while ((st.size() != 0)) {
                    answer.push_back("Pop");
                    st.pop();
                }           
            }
            ++i;
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
