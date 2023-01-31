class Solution {
public:
    bool canWinNim(int n) {   
        return (((n - 7) % 4) == 0) || (((n - 6) % 4) == 0) || (((n - 1) % 4) == 0);
    }
};

int main() {
  
  
  
  return 0;  
}
