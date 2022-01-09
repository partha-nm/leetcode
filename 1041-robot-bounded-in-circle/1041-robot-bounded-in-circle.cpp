class Solution {
public:
    bool isRobotBounded(string i) 
    {
        int x =0,y=0;
        char dir = 'N';
        for(auto &p:i)
        {
            if(p == 'G')
            {
                if(dir == 'N') y++;
                else if(dir == 'S') y--;
                else if(dir == 'E') x++;
                else if(dir == 'W') x--;
            }
            else if(p == 'R')
            {
                if(dir == 'N') dir = 'E';
                else if(dir == 'S') dir = 'W';
                else if(dir == 'E') dir = 'S';
                else if(dir == 'W') dir = 'N';
            }
            else
            {
                if(dir =='N') dir = 'W';
                else if(dir=='S') dir = 'E';
                else if(dir == 'E') dir = 'N';
                else if(dir == 'W') dir = 'S';
            }
        }
        cout<<dir<<x<<" "<<y<<endl;
        if((x==0 && y==0)) return true;
        if(dir != 'N') return true;
        return false;
    }
};