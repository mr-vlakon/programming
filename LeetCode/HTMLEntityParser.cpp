class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> um;
        um["&quot;"] = "\"";
        um["&apos;"] = "'";
        um["&amp;"] = "&";
        um["&gt;"] = ">";
        um["&lt;"] = "<";
        um["&frasl;"] = "/";
        string answer;
        int pos = -1;
        string temp;
        unordered_map<string, string>::iterator it;
        for (int i = 0; i != text.size(); ++i) {
            if (text[i] == '&') {
                if (pos != -1) {
                    answer += string{text.cbegin() + pos, text.cbegin() + i}; 
                }
                pos = i;
            } else if (text[i] == ';' && pos != -1) {
                temp = string{text.cbegin() + pos, text.cbegin() + i + 1};
                it = um.find(temp);
                if (it != um.cend()) {
                    answer += it->second;
                } else {
                    answer += temp;
                }
                pos = -1;
            } else {
                if (pos == -1) {
                    answer += text[i];
                }
            }         
        }
        if (pos != -1) {
            answer += string{text.cbegin() + pos, text.cend()};                    
        }
       return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
