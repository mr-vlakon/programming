class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {                
        int answer = INT_MAX;
        vector<int> v(110001, INT_MAX);
        if (x < y)
        {
            v[x] = 0;
            v[x + 1] = 1;
            if ((x - 1) >= 0)
            {
                v[x + 1] = 1;
            }       
            for (int i = x; i != 100000; ++i)
            {
                if ((i + 1) < v.size())
                {
                    v[i + 1] = min(v[i + 1], v[i] + 1);
                }
                if ((i - 1) >= 0)
                {
                    v[i - 1] = min(v[i - 1], v[i] + 1);
                }
                if ((i/5) >= 0)
                {
                    if (((i/5) == 0) && (i % 5) == 0)
                    {
                        v[i/5] = min(v[i/5], v[i] + 1);
                    }
                    else if ((i % 5) == 0)
                    {
                        v[i/5] = min(v[i/5], v[i] + 1);    
                    }
                }
                if ((i/11) >= 0)
                {
                    if (((i/11) == 0) && (i % 11) == 0)
                    {
                        v[i/11] = min(v[i/11], v[i] + 1);
                    }
                    else if ((i % 11) == 0)
                    {
                        v[i/11] = min(v[i/11], v[i] + 1);    
                    }
                }
                answer = min(answer, abs(v[i] + abs(i - y)));       
            }
        }
        else if (x > y)
        {
            v[x] = 0;
            v[x + 1] = 1;
            if ((x - 1) >= 0)
            {
                v[x - 1] = 1;
            }
            v[x + 2] = 2;
            v[x + 3] = 3;
            v[x + 4] = 4;
            v[x + 5] = 5;
            v[x + 6] = 6;
            for (int i = x + 6; i >= 0; --i)
            {
                if ((i + 1) < v.size())
                {
                    v[i + 1] = min(v[i + 1], v[i] + 1);
                }
                if ((i - 1) >= 0)
                {
                    v[i - 1] = min(v[i - 1], v[i] + 1);
                }
                
                if ((i/5) >= 0)
                {
                    if ((i % 5) == 0)
                    {
                        v[i/5] = min(v[i/5], v[i] + 1);    
                    }
                }
                
                if ((i/11) >= 0)
                {
                    if ((i % 11) == 0)
                    {
                        v[i/11] = min(v[i/11], v[i] + 1);    
                    }
                }
                v[i + 2] = min(v[i + 2], v[i] + 2);
                v[i + 3] = min(v[i + 3], v[i] + 3);
                v[i + 4] = min(v[i + 4], v[i] + 4);
                v[i + 5] = min(v[i + 5], v[i] + 5);
                v[i + 6] = min(v[i + 6], v[i] + 6);
                if (((i + 2) % 5) == 0)
                {
                    v[(i + 2) / 5] = min(v[(i + 2) / 5], v[i + 2] + 1);
                }
                if (((i + 3) % 5) == 0)
                {
                    v[(i + 3) / 5] = min(v[(i + 3) / 5], v[i + 3] + 1);
                }
                if (((i + 4) % 5) == 0)
                {
                    v[(i + 4) / 5] = min(v[(i + 4) / 5], v[i + 4] + 1);
                }
                if (((i + 5) % 5) == 0)
                {
                    v[(i + 5) / 5] = min(v[(i + 5) / 5], v[i + 5] + 1);
                }
                if (((i + 6) % 5) == 0)
                {
                    v[(i + 6) / 5] = min(v[(i + 6) / 5], v[i + 6] + 1);
                }

                
                if (((i + 2) % 11) == 0)
                {
                    v[(i + 2) / 11] = min(v[(i + 2) / 11], v[i + 2] + 1);
                }
                if (((i + 3) % 11) == 0)
                {
                    v[(i + 3) / 11] = min(v[(i + 3) / 11], v[i + 3] + 1);
                }
                if (((i + 4) % 11) == 0)
                {
                    v[(i + 4) / 11] = min(v[(i + 4) / 11], v[i + 4] + 1);
                }
                if (((i + 5) % 11) == 0)
                {
                    v[(i + 5) / 11] = min(v[(i + 5) / 11], v[i + 5] + 1);
                }
                if (((i + 6) % 11) == 0)
                {
                    v[(i + 6) / 11] = min(v[(i + 6) / 11], v[i + 6] + 1);
                }                
                answer = min(answer, abs(v[i] + abs(i - y)));
            }
        }
        else
        {
            return 0;
        }
        return min(v[y], answer);
    }
};

int main()
{

  return 0;
}
