class Solution {
public:
    string makeGood(string s) {
     
        while (true) {
            int cnt = 0;
            for (int i = 1; i != s.size(); ++i) {
                if (tolower(s[i - 1]) == tolower(s[i]) && s[i - 1] != s[i]) {
                    s.erase(s.cbegin() + i);
                    s.erase(s.cbegin() + i - 1);
                    cnt = 1;
                    break;
                }
                
            }
            //cout << "s = " << s << endl;
            if (cnt == 0 || s.size() == 0) {
                break;
            }
            
        }
        return s;
    }
};

innt main() {
  
  
  
  return 0;  
}
