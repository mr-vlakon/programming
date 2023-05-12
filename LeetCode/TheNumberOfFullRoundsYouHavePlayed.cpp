class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int h1 = stoi(string(loginTime.cbegin(), loginTime.cbegin() + 3));
        int m1 = stoi(string(loginTime.cbegin() + 3, loginTime.cend()));
        int convert1 = h1*60 + m1;
        h1 = stoi(string(logoutTime.cbegin(), logoutTime.cbegin() + 3));
        m1 = stoi(string(logoutTime.cbegin() + 3, logoutTime.cend()));
        int convert2 = h1*60 + m1;
        int t1 = ceil(static_cast<double>(convert1) / 15.0);
        int t2 = floor(static_cast<double>(convert2) / 15.0);
        if (t2 < t1 && loginTime > logoutTime) {
            return 96 - t1 + t2;
        } else if (t2 < t1) return 0;
        return t2 - t1;
    }
};

int main() {
  
  
  return 0;  
}
