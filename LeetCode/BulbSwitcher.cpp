class Solution {
public:
    int bulbSwitch(int n) {
        int start = 1;
        int x = 1;
        int i = 0;
        while (x <= n) {
            start += 2;
            x += start;
            i++;
        }
        return i;
    }
};

int main() {
  
  
  return 0;  
}
