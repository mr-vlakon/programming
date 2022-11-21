class Solution {
public:
    vector<int> diStringMatch(string s) {
        size_t n = s.size() + 1;
        deque<int> d;
        for (decltype(d.size()) i = 0; i < n; ++i) {
            d.push_back(i);
        }
        vector<int> answer;
        for (int i = 0; i != s.size(); i++) {
            if (s[i] == 'I') {
                answer.push_back(d[0]);
                d.erase(d.begin());
            } else {
                answer.push_back(d.back());
                d.erase(--d.end());
            }
        }
        answer.push_back(d[0]);
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
