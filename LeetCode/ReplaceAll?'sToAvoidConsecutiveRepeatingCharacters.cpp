class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i != s.size(); ++i) {
            if (i == 0 && s[i] == '?') {
                char c = s[1];
                if (s[1] != '?') {
                    if (s[1] == 'a') {
                        s[i] = 'b';
                    } else if (s[1] == 'z') {
                        s[i] = 'a';  
                    } else {
                        s[i] = 'a';
                    }
                } else {
                    s[i] = 'a';
                }
            } else if (s[i] == '?') {
                char c = s[i + 1];
                if (s[i + 1] != '?') {
                    if (s[i + 1] == 'a') {
                        if (s[i + 1] != 'b') {
                            if (s[i - 1] != 'b') {
                                s[i] = 'b';
                            } else {
                                s[i] = 'z';
                            }
                        } else {
                            if (s[i - 1] != 'c') {
                                s[i] = 'c';
                            } else {
                                s[i] = 'a';
                            }
                        }
                    } else if (s[i + 1] == 'z') {
                        if (s[i - 1] != 'a') {
                            s[i] = 'a';
                        } else {
                            s[i] = 'b';
                        }
                    } else {
                        if (s[i - 1] != 'a') {
                            s[i] = 'a';
                        } else {
                            if (s[i + 1] != 'b') {
                                s[i] = 'b';
                            } else {
                                s[i] = 'z';
                            }
                        }
                    }
                } else {
                    if (s[i - 1] != 'a') {
                        s[i] = 'a';
                    } else {
                        s[i] = 'b';
                    }
                }      
            }
        }
        return s;
    }
};

int main() {
  
  
  
  return 0;  
}
