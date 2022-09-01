class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int prev = 0;
        string res;
        for (const auto &e: spaces) {
            res += string(s.begin() + prev, s.begin() + e) + " ";
            prev = e;
        }
        res += string(s.begin() + prev, s.end());
        return res;
    }
};

int main() {
  
  return 0;  
}
