class Solution {
public:
    bool queryString(string s, int n) {
        string s1;
        int k = 1;
        while (k <= n ) {
            s1 = "";
            int q = k;
            while(q) {
                int tmp = q % 2;
                s1.push_back(static_cast<char>(tmp + '0'));
                q /= 2;
            }
            reverse(s1.begin(), s1.end());
            ++k;
            if (s.find(s1) == std::string::npos) return false;
        }
        return true;       
    }
};

int main() {

  return 0;  
}
