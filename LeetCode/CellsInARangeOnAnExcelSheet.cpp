class Solution {
public:
    vector<string> cellsInRange(string s) {
        char c = s[4];
        char q = s[1];
        vector<string> answer;
        char beg = s[0];
        char end = s[3];
        while (beg <= end) {
            char qq = q;
            while (qq <= c) {
                string tmp;
                tmp.push_back(beg);
                tmp.push_back(qq);
                answer.push_back(tmp);
                ++qq;
            }
            ++beg;
        }
        return answer;
        
    }
};

int main() {
  
  
  
  return 0;  
}
