class Solution {
public:
    string freqAlphabets(string s) {
        reverse(s.begin(), s.end());
        string result;
        string tmp(2, '0');
        int x = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == '#') {
                tmp[1] = s[i + 1];
                tmp[0] = s[i + 2];
                i += 3;
                x = stoi(tmp);
                result.push_back(x + 'a' - 1);
            } else {
                result.push_back(s[i] - '0' + 'a' - 1);
                ++i;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
  
  
  return 0;  
}
