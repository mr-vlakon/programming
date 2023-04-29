class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> answer;
        vector<bool> v1(A.size(), 0);
        vector<bool> v2(B.size(), 0);
        int cnt = 0;
        int prev = 0;
        for (int i = 0; i != A.size(); ++i) {
            v1[A[i] - 1] = true;
            v2[B[i] - 1] = true;
            if (v1[A[i] - 1] == v2[A[i] - 1]) {
                ++prev;
            }
            if (v2[B[i] - 1] == v1[B[i] - 1] && A[i] != B[i]) {
                ++prev;
            }   
            answer.push_back(prev);
        }
        return answer;
    }
};
/*
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> answer;
        vector<bool> v1(A.size(), 0);
        vector<bool> v2(B.size(), 0);
        int cnt = 0;
        for (int i = 0; i != A.size(); ++i) {
            v1[A[i] - 1] = true;
            v2[B[i] - 1] = true;
            cnt = 0;
            for (int j = 0; j != v1.size(); ++j) {
                if (v1[j] == true && v2[j] == true) {
                    ++cnt;
                }
            }
            answer.push_back(cnt);
        }
        return answer;
    }
};
*/
/*
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> answer;
        vector<bool> v1(50, 0);
        vector<bool> v2(50, 0);
        int cnt = 0;
        for (int i = 0; i != A.size(); ++i) {
            v1[A[i] - 1] = true;
            v2[B[i] - 1] = true;
            cnt = 0;
            for (int j = 0; j != v1.size(); ++j) {
                if (v1[j] == true && v2[j] == true) {
                    ++cnt;
                }
            }
            answer.push_back(cnt);
        }
        return answer;
    }
};
*/

int main() {
  
  
  
  return 0;  
}
