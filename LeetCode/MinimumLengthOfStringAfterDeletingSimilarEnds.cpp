class Solution {
public:
    int minimumLength(string s) {
        int start = 0;
        int end = s.size() -1;
        char c;
        while (start < end) {
            c = s[start];
            while (start <= end && s[start] == s[end]) {
                ++start;
            }
            while (start <= end && c == s[end]) {
                --end;
            }
            if (s[start] != s[end])  {
                break;
            }
        }
        return end - start + 1;
    }
};

int main() {

  
  return 0;  
}
