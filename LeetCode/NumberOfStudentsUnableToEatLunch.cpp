class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        for (int i = sandwiches.size() - 1; i >= 0; --i) {
            st.push(sandwiches[i]);
        }
        deque<int> deq(students.cbegin(), students.cend());
        int cnt = 0;
        while (deq.size() != 0) {
            if (deq[0] == st.top()) {
                st.pop();
                cnt = 0;
                deq.erase(deq.cbegin());
            } else {
                int top = deq[0];
                deq.erase(deq.cbegin());
                deq.push_back(top);
                ++cnt;
                if (cnt > deq.size()) {
                    break;
                }
            }
        }
        return deq.size();
    }
};

int main() {
  
  
  
  return 0;  
}
