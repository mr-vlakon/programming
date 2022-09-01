class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        istringstream is(s);
        string res;
        is >> res;
        return res.size();
    }
};

int main() {
  
  return 0;  
}
