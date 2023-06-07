class Solution {
public:
    int minimizedStringLength(string s) {
        int answer = 0;
        vector<bool> v(26, 0);
        for (const auto &e: s) {
            if (v[e - 'a'] == false) {
                ++answer;
                v[e - 'a'] = true;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
