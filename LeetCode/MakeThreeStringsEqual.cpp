class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int maxSize = max<size_t>(max<size_t>(s1.size(), s2.size()), s3.size());
        int answer = 0;
        if (s1.size() == maxSize) {
            int i = 0;
            int size = maxSize - i - 1;
            bool cut = false;
            if (s1 == s2 && s2 == s3) return answer;
            while (size >= 1) {
                s1.pop_back();
                ++answer;
                if (size >= s2.size()) {
                    cut = true;
                } else if (s2[size] != s1[size]) {
                    s2.pop_back();
                    ++answer;
                }
                if (size >= s3.size()) {
                } else if (s3[size] != s1[size]) {
                    s3.pop_back();
                    ++answer;
                }
                if (s1 == s2 && s2 == s3) return answer;
                cut = false;
                ++i;
                size = maxSize - i - 1;
            }
        } else if (s2.size() == maxSize) {
            int i = 0;
            int size = maxSize - i - 1;
            bool cut = false;
            if (s1 == s2 && s2 == s3) return answer;
            while (size >= 1) {
                if (s1 == s2 && s2 == s3) return answer;
                s2.pop_back();
                ++answer;
                if (size >= s1.size()) {
                    cut = true;
                } else if (s2[size] != s1[size]) {
                    s1.pop_back();
                    ++answer;
                }
                if (size >= s3.size()) {
                } else if (s3[size] != s2[size]) {
                    s3.pop_back();
                    ++answer;
                }
                cut = false;
                ++i;
                size = maxSize - i - 1;
            }            
        } else {
            int i = 0;
            int size = maxSize - i;
            bool cut = false;
            if (s1 == s2 && s2 == s3) return answer;
            while (size >= 1) {
                if (s1 == s2 && s2 == s3) return answer;
                s3.pop_back();
                ++answer;
                if (size >= s1.size()) {
                } else if (s3[size] != s1[size]) {
                    s1.pop_back();
                    ++answer;
                }
                if (size >= s2.size()) {
                } else if (s2[size] != s3[size]) {
                    s2.pop_back();
                    ++answer;
                }
                cut = false;
                ++i;
                size = maxSize - i - 1;
            }   
        }    
        string str1 = string(s1.cbegin(), s1.cbegin() + min<size_t>(1, s1.size()));
        string str2 = string(s2.cbegin(), s2.cbegin() + min<size_t>(1, s2.size()));
        string str3 = string(s3.cbegin(), s3.cbegin() + min<size_t>(1, s3.size()));
        if ((str1 != str2) || (str1 != str3) || (str2 != str3)) {
            return -1;
        }
        return answer;
    }
};

int main()
{



  return 0;
}
