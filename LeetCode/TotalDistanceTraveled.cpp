class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int result = 0;
        int counter = 0;
        while (mainTank) {
            if (counter == 5 && additionalTank) {
                ++mainTank;
                --additionalTank;
                counter = 1;
            } else {
                ++counter;
            }
            result += 10;
            --mainTank;
        }
        if (counter == 5 && additionalTank)  {
            result += 10;
        }
        return result;
    }
};

int main() {
  
  return 0;
}
