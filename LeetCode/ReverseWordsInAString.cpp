class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string s1;
        vector<string> v;
        while(is >> s1) {
            v.push_back(s1);
        }
        s1 = "";
        reverse(v.begin(), v.end());
        for (const auto &e: v) {
            s1 += e + " ";
        }
        s1 = s1.substr(0, s1.size() - 1);
        return s1;
    }
};

int main() {
  
  return 0; 
}
