class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k != 1) {
            sort(s.begin(), s.end());
            return s;
        }
        int j = 0;
        string min = s;
        while(j != s.size()) {
            auto c = s[0];
            s.push_back(c);
            s.erase(s.begin());
            if (min > s) {
                min = s;
            }
            ++j;
        }
        return min;
    }
};

int main() {
  
  
  return 0;  
}
