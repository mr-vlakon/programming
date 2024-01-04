class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int start1 = 0;
        int start2 = 0;
        bool answer = false;
        while ((start1 != str1.size()) && (start2 != str2.size()))
        {      
            char t = str1[start1];
            if (t == str2[start2]) {
                ++start1;
                ++start2;
                continue;
            }
            if (t == 'z') 
            {
                t = 'a';
            }
            else
            {
                ++t;    
            }
            if (t == str2[start2]) {
                ++start2;
            }
            ++start1;
        }
        return start2 == str2.size();
    }
};

int main()
{



  return 0;
}
