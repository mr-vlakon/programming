class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for (int i = 0; i < s1.size(); ++i) {
            if ((i + 2) < s2.size() && s1[i] != s2[i]) {
                if (s2[i + 2] == s1[i]) {
                    swap(s2[i + 2], s2[i]);
                } else {
                    return false;
                }
            } else {
                if (s2[i] != s1[i])  {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{



  return 0;
}
