class Solution {
public:
    string reverseOnlyLetters(string s) {
        string res;
        for (const auto &e: s) {
            if (isalpha(e))
                res.push_back(e);
        }
        
        int i = 0;
        reverse(res.begin(), res.end());
        string answer;
        for (const auto &e: s) {
            if (isalpha(e)) {
                answer.push_back(res[i]);
                ++i;
            } else {
                answer.push_back(e);
            }
        } 
        return answer;
    }
};

int main() {


  return 0;  
}
