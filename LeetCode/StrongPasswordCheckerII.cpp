class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        auto pos = password.find_first_of("qwertyuioplkjhgfdsazxcvbnm");
        if (pos == string::npos) return false;
        pos = password.find_first_of("QWERTYUIOPLKJHGFDSAZXCVBNM");
        if (pos == string::npos) return false;
        pos = password.find_first_of("0123456789");
        if (pos == string::npos) return false;
        pos = password.find_first_of("!@#$%^&*()-+");
        if (pos == string::npos) return false;
        for (decltype(password.size()) i = 0; i != password.size() - 1; ++i) {
            if (password[i] == password[i + 1])
                return false;
        }
        return true;
    }
};

int main() {
  
  
  return 0;  
}
