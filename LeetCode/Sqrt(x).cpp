class Solution {
public:
    int mySqrt(int x) {
        unsigned i = 0;
        unsigned res = 0;
        while(res <= x) {            
            ++i;
            res = i * i;
        }
        return i - 1;
    }
};

int main() {
  
  return 0; 
}
