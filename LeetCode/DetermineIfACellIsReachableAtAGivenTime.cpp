class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffx = abs(sx - fx);
        int diffy = abs(sy - fy);
        int maxV = max(diffx, diffy);
        if (maxV == 0) {
            if  (t == 1) return false;
            else return true;
        }
        return maxV <= t;
     }
};

int main()
{

  return 0;
}
