class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](vector<int> &lhs, vector<int> &rhs) {
            return lhs[1] < rhs[1];
        });
        stable_sort(properties.begin(), properties.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] > rhs[0];
        });
        int answer = 0;
        stack<pair<int, int>> st;
        for (int i = 0; i != properties.size(); ++i) {
            while ((st.size() != 0) && (st.top().first <= properties[i][0])) {
                st.pop();
            }
            while ((st.size() != 0) && (st.top().second <= properties[i][1])) {
                st.pop();
            } 
            if (st.size() == 0) {
                st.push({properties[i][0], properties[i][1]});
            } else {
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
