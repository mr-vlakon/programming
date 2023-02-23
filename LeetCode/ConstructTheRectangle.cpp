class Solution {
public:
    vector<int> constructRectangle(int area) {
        int first = 0;
        int second = 0;
        int start = (area / 2) + (area % 2);
        while (start >= 1) {
            if (area % start == 0) {
                first = area / start;
                second = start;
                if (first >= second) {
                    break;
                }
            }
            --start;
        }
        return {first, second};
    }
};

int main() {
  
  
  return 0;  
}
