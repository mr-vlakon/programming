class Solution {
public:
    void generate(const string &s, int &i, string &str, int &comma, int &dot) {
        if (i == (s.size() - 2)) {
            if (comma != 0 && dot <= 2) {
                str.push_back(s[i]);
                if (str.back() == '0' && dot == 1) {
                    str.pop_back();
                    return;
                }   
                str.push_back(')');
                result.push_back(str);
                str.pop_back();
                str.pop_back();
            }
            return;
        }
        if (comma == 0) {
            str.push_back(s[i]);
            str.push_back(',');
            str.push_back(' ');
            if (!((s[i] == '0') && dot == 1)) {
                prev = dot;
                dot = 0;     
                comma = str.size() - 2;
                ++i;
                generate(s, i, str, comma, dot);
                dot = prev;
                comma = 0;
                --i;
            }
            str.pop_back();
            str.pop_back();
            str.pop_back();
            str.push_back(s[i]);
            if (str[1] != '0' || (str[1] == '0' && dot == 1)) {
                ++i;
                generate(s, i, str, comma, dot);
                --i;
            }
            str.pop_back();             
            if (dot == 0) {
                str.push_back(s[i]);
                str.push_back('.');
                dot = 1;
                ++i;
                generate(s, i, str, comma, dot);
                --i;
                dot = 0;
                str.pop_back();
                str.pop_back();
            }     
        } else if (comma != 0) {
            str.push_back(s[i]);    
            if (str[comma + 2] != '0' || (str[comma + 2] == '0' && dot == 1) || 
            ((i + 1) == (s.size() - 1))) {
                ++i;
                generate(s, i, str, comma, dot);
                --i;
            }
            str.pop_back();     
            if (dot == 0) {
                str.push_back(s[i]);
                str.push_back('.');
                dot = 1;
                ++i;
                generate(s, i, str, comma, dot);
                --i;
                dot = 0;
                str.pop_back();
                str.pop_back();
            }     
        }
    }
    vector<string> ambiguousCoordinates(string s) {
        string empty;
        empty.push_back('(');
        int comma = 0;
        int dot = 0;
        int i = 1;
        generate(s, i, empty, comma, dot);
        return result;
    }
private:
    int prev = 0;
    vector<string> result;
};

int main() {
  
  
  
  return 0;  
}
