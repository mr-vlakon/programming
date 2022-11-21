class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int i = 1;
        while (i != n) {
            int A = i;
            int B = n - i;
            int aa = A;
            int bb = B;
            bool status1 = false;
            while (aa) {
                int tmp = aa % 10;
                if (tmp == 0){ 
                    status1 = true;
                    break;
                }
                aa /= 10;
            }
            if (status1) {
                ++i;
                continue;
            }
            bool status2 = false;
            while (bb) {
                int tmp = bb % 10;
                if (tmp == 0){ 
                    status2 = true;
                    break;
                }
                bb /= 10;
            }
            if (!status1 && !status2) {
                return {A, B};
            }
            ++i;
            
        }
        return {};
    }
};

int main() {
  
  
  
  return 0;  
}
