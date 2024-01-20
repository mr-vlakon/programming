class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int answer = 0;
        
        if (abs(c - e) == abs(d - f))
        {
            if (abs(c - a) == abs(d - b))
            {
                int x = 1;
                if ((a >= e) && (a <= c))
                {
                    if ((b >= f) && (b <= d))
                    {
                        return 2;
                    }    
                    if ((b <= f) && (b >= d))
                    {
                        return 2;
                    }    

                
                }
                if ((a <= e) && (a >= c))
                {
                    if ((b >= f) && (b <= d))
                    {
                        return 2;
                    }    
                    if ((b <= f) && (b >= d))
                    {
                        return 2;
                    }    

                    
                }

                
                return 1;
            }
            return 1;
        }
        
        if (a == e || b == f)
        {
            if (a == e)
            {
                if (c == a)
                {
                    if ((d >= b) && (d <= f))
                    {
                        return 2;
                    }
                    if ((d >= f) && (d <= b))
                    {
                        return 2;
                    } 
                }
            }
            if (b == f)
            {
                if (d == b)
                {
                    if ((c >= a) && (c <= e))
                    {
                        return 2;
                    }
                    if ((c >= e) && (c <= a))
                    {
                        return 2;
                    } 
                }
            }
            return 1;
        }
        return 2;        
    }
};

int main()
{


  return 0;
}
