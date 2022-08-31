class Solution {
public:
    string greatestLetter(string s) {
        sort(s.begin(), s.end());
        auto it = s.begin();
        string res;
        while (it != s.end()) {
            if(!islower(*it)) {
                if((find(s.cbegin(),s.cend(),*it) != s.cend()) &&
                   find(s.cbegin(),s.cend(),tolower(*it)) != s.cend()) 
                {
                    res = *it;
                }
            }
            ++it;
        }
        return res;
    }
};

int main() {

  return 0;  
}
