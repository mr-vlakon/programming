class Solution {
public:
    int smallestEvenMultiple(int n) {
        int i = n;
        while (true) {
            if ( i % 2 == 0 && i % n == 0)
                return i;
            ++i;
        }
        return 0;
    }
};

int main() {
  
  
  return 0;  
}
