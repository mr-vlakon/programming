class Solution {
public:
    int compareVersion(string version1, string version2) {
        int start1 = 0;
        int start2 = 0;
        string tmp1;
        string tmp2;
        while ((start1 < version1.size()) || (start2 < version2.size())) {
            while (start1 < version1.size()  && version1[start1] == '0') {
                ++start1;
            }
            while (start2 < version2.size()  && version2[start2] == '0') {
                ++start2;
            }
            while ((start1 < version1.size() && version1[start1] != '.') || (start2 < version2.size()  && version2[start2] != '.')) {
                if (start1 < version1.size() && version1[start1] != '.') {
                    tmp1.push_back(version1[start1]);
                    ++start1;
                }
                if (start2 < version2.size() && version2[start2] != '.') {
                    tmp2.push_back(version2[start2]);
                    ++start2;
                }
            }
            if (tmp1.size() != 0 && tmp2.size() != 0) {
                if (stoi(tmp1) > stoi(tmp2)) {
                    return 1;
                } else if (stoi(tmp1) < stoi(tmp2)) {
                    return -1;
                }
                tmp1.resize(0);
                tmp2.resize(0);
            } else if (tmp1.size() != 0) {
                return 1;
            } else if (tmp2.size() != 0) {
                return -1;
            }
            if (start1 != version1.size()) ++start1;
            if (start2 != version2.size()) ++start2;
        }
        return 0; 
    }
};

int main() {
  
  
  
  
  return 0;  
}
