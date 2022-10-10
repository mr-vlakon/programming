class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string result;
        for (const auto &e: words) {
            result += e;
            if (result == s)
                return true;
        }
        return false; 
    }
};

int main() {
  
  
  return 0;  
}
