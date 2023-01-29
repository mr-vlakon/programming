class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        stack<pair<int, int>> st;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while((st.size() != 0) && (temperatures[i] >= st.top().first)) {
                st.pop();
            }
            if (st.size() == 0) {
                answer[i] = 0;
            } else {
                answer[i] = st.top().second - i;
            }
            st.push({temperatures[i], i});
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
