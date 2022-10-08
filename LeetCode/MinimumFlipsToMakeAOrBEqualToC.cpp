class Solution {
public:
    int minFlips(int a, int b, int c) {
        string binaryA;
        string binaryB;
        while (a) {
            int tmp = a % 2;
            binaryA.push_back(tmp + '0');
            a /= 2;
        }
        while (binaryA.size() != 32) {
            binaryA.push_back('0');
        }
        while (b) {
            int tmp = b % 2;
            binaryB.push_back(tmp + '0');
            b /= 2;
        }
        while (binaryB.size() != 32) {
            binaryB.push_back('0');
        }
        string binaryC;
        while (c) {
            int tmp = c % 2;
            binaryC.push_back(tmp + '0');
            c /= 2;
        }
        while (binaryC.size() != 32) {
            binaryC.push_back('0');
        }
        int cnt = 0;
        for (decltype(binaryA.size()) i = 0; i != binaryA.size(); ++i) {
            if (binaryC[i] == '0') {
                if (binaryA[i] == '1')
                    ++cnt;
                if (binaryB[i] == '1')
                    ++cnt;
            }
            if (binaryC[i] == '1') {
                if (binaryA[i] == '1' || binaryB[i] == '1') {
                    
                } else {
                    ++cnt;
                }
            }
            
        }
                
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}
