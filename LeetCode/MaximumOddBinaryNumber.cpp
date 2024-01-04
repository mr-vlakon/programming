class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = count(s.cbegin(), s.cend(), '1');
        int cnt = cnt1 - 1;
        string answer(s.size(), '0');
        for (int i = 0; i != s.size(); ++i) {
            if (cnt > 0) {
                answer[i] = '1';
                --cnt;
            }
        }
        if (cnt1 != 0) {
            answer[answer.size() - 1] = '1';
        }
        return answer;
    }
};

int main()
{



  return 0;
}
