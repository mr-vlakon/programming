class Solution {
public:
    string truncateSentence(string s, int k) {
        istringstream is(s);
        string res;
        int i = 0;
        while ((is >> s) && (i != k)) {
            if (i != k - 1)
                res += s + " ";
            else
                res += s;
            ++i;
        }
        return res;
    }
};

int main() {
  
  return 0;  
}
