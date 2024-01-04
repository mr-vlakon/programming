class Solution {
public:
    int differenceOfSums(int n, int m) {
        int i = 1;
        int num1 = 0;
        while (i <= n) {
            if ((i % m ) != 0) {
                num1 += i;
            }
            ++i;
        }
        i = 1;
        int num2 = 0;
        while (i <= n) {
            if ((i % m ) == 0) {
                num2 += i;
            }
            ++i;
        }
        return num1 - num2;
    }
};

int main()
{


  return 0;
}
