class Solution {
public:
    bool rotateString(string s, string goal) {
        int i = 0;
        if (s == goal) return true;
        while (i != s.size()) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) return true;
            ++i;
        }
        return false;
    }
};

int main() {

  return 0;  
}
