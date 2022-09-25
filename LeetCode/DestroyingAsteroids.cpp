class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int i = 0;
        long long mas = mass;
        while (i != asteroids.size()) {
            if (asteroids[i] <= mas) {
                mas += asteroids[i];
            } else
                return false;      
            ++i;
        }
        return true;
    }
};

int main() {
  
  
  return 0;  
}
