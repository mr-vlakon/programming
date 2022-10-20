class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char, string> um;
        vector<string> v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (int i = 0; i != 26; ++i) {
            um['a' + i] = v[i];
        }
        set<string> s;
        for (const auto &e: words) {
            string tmp;
            for (const auto &p: e) {
                tmp += um[p];
            }
            s.insert(tmp);
        }
        
        
        return s.size();
    }
};

int main() {
  
  
  return 0;  
}
