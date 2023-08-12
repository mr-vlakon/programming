class Solution {
public:
    string finalString(string s) {
        int start = 0;
        string result;
        while (start < s.size()) {
            if (s[start] == 'i') {
                if (result.size() != 0) {
                    reverse(result.begin(), result.end());
                }
            } else {
                result.push_back(s[start]);
            }
            ++start;
        }
        return result;
    }
};

int main() {




  return 0;
}
