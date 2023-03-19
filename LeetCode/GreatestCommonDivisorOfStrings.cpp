class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string answer;
        if (str1.size() < str2.size()) {
            string tmp;
            string tmp2;
            string str;
            for (const auto &e: str1) {
                tmp.push_back(e);
                if ((str2.size() % tmp.size()) == 0 && (str1.size() % tmp.size()) == 0) {
                    tmp2 = tmp;
                    while (tmp2.size() < str2.size()) {
                        tmp2 += tmp;
                    }
                    if (tmp2 == str2) {
                        str = tmp;
                        while (str.size() < str1.size()) {
                            str += tmp;
                        }
                        if (str == str1) {
                            answer = tmp;
                        }
                    }
                    tmp2.resize(0);      
                }
            }
        } else {
            string tmp;
            string tmp2;
            string str;
            for (const auto &e: str2) {
                tmp.push_back(e);
                if ((str1.size() % tmp.size()) == 0 && (str2.size() % tmp.size()) == 0) {
                    tmp2 = tmp;
                    while (tmp2.size() < str1.size()) {
                        tmp2 += tmp;
                    }
                    if (tmp2 == str1) {
                        str = tmp;
                        while (str.size() < str2.size()) {
                            str += tmp;
                        }
                        if (str == str2) {
                            answer = tmp;
                        }
                    }
                    tmp2.resize(0);      
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
