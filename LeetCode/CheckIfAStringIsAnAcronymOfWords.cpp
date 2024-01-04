class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string check;
        for (const auto &e: words) {
            check.push_back(e[0]);
        }
        return check == s;
    }
};

int main()
{


  return 0;
}
