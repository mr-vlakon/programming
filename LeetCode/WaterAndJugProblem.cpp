class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (targetCapacity > (jug1Capacity + jug2Capacity)) return false;
        return (targetCapacity % gcd(jug1Capacity, jug2Capacity)) == 0;
    }
};
/*
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (targetCapacity > (jug1Capacity + jug2Capacity)) return false;
        queue<int> q;
        vector<bool> us(targetCapacity + 1, 0);
        q.push(targetCapacity);
        //us[targetCapacity] = true;
        int x = 0;
        int y = 0;
        int z = 0;
        int top = 0;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            x = top - jug1Capacity;
            y = top - jug2Capacity;
            z = top - gcd(jug1Capacity, jug2Capacity);
            if (top == 0) return true;
            if (x >= 0 && !us[x]) {
                us[x] = true;
                q.push(x);
            }
            if (y >= 0 && !us[y] && x != y) {
                us[y] = true;
                q.push(y);
            }
            if (z >= 0 && !us[z] && x != z && z != y) {
                us[z] = true;;      
                q.push(z);
            }
        }
        return false;
    }
};
*/

int main() {
  
  
  
  return 0;  
}
