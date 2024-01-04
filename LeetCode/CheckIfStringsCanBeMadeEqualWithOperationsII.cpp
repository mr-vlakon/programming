class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string strEven1;
        string strOdd1;
        string strEven2;
        string strOdd2;
        for (int i = 0; i != s1.size(); ++i) {
            if ((i % 2) == 0) {
                strEven1.push_back(s1[i]);
                strEven2.push_back(s2[i]);
            } else {
                strOdd1.push_back(s1[i]);
                strOdd2.push_back(s2[i]);    
            }
        }
        sort(strEven1.begin(), strEven1.end());
        sort(strEven2.begin(), strEven2.end());
        sort(strOdd1.begin(), strOdd1.end());
        sort(strOdd2.begin(), strOdd2.end());
        return (strEven1 == strEven2) && (strOdd1 == strOdd2);
    }
};

int main()
{


  return 0;
}

