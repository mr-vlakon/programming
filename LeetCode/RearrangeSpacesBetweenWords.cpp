class Solution {
public:
    string reorderSpaces(string text) {
        istringstream is(text);
        int initialSize = text.size();
        string s;
        string result;
        int cnt = 0;
        string tmp(text);
        while (is >> s) {
            result += s;
            ++cnt;
        }
        int afterSize = result.size();
        int numberSpaces = initialSize - afterSize;
        if (cnt == 1) return result + string(numberSpaces, ' ');
        int total = numberSpaces / (cnt - 1);
        int ost = numberSpaces % (cnt - 1);
        istringstream iss(tmp);
        string res;
        string str;
        while (iss >> str) {
            res += str + string(total, ' ');
        }
        res.erase(res.end() - total,res.end());
        res += string(ost, ' ');
        return res;        
    }
};

int main() {
  
  
  return 0;  
}
