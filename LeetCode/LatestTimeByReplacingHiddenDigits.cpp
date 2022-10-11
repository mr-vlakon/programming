class Solution {
public:
    string maximumTime(string time) {
        auto pos = time.find(':');
        string s(time.cbegin(), time.cbegin() + pos);
        if (s[0] == '?') {
            if (s[1] == '?' || s[1] < '4')
                s[0] = '2';
            else {
                s[0] = '1';
            }
        }
        if (s[1] == '?') {
            if(s[0] == '2') {
                s[1] = '3';
            } else {
                s[1] = '9';
            }
        }
        cout << s << endl;
        string ss(time.cbegin() + pos + 1, time.cend());
        if (ss[0] == '?') {
            ss[0] = '5'; 
        }
        if (ss[1] == '?') {
            ss[1] = '9';
        }

        return s + ":" + ss;
        
    }
};

int main() {
  
  
  return 0;  
}
