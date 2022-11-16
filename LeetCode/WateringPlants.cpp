class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int cap = capacity;
        for (int i = 0; i != plants.size(); ++i) {
            if (cap >= plants[i]) {
                cap -= plants[i];
                ++steps;
            } else {
                steps += i;
                steps += i + 1;
                cap = capacity;
                cap -= plants[i];
            } 
        }
        return steps;
    }
};

int main() {
  
  
  
  return 0;  
}
