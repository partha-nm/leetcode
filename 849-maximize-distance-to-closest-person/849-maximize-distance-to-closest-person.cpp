class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
       int ans =-1, first = -1, second = -1, val =-1;
       for(int i=0; i<seats.size(); i++)
       {
           if(seats[i] == 1)
           {
               if(first == -1) first = i;
               else 
               {
                   second = i;
                   int p = (second-first)/2;
                   if(val < p) 
                   {
                       val = p;
                   }
                   first = second;
               }
           }
       }
       int val1 = -1, val2 =-1;
       for(int i=0; i<seats.size(); i++) if(seats[i] == 1){val1 = i; break;}
        for(int i=seats.size()-1; i>=0; i--) if(seats[i] == 1){val2 = seats.size()-1 - i; break;}
        int chk = max(val, max(val1, val2));
        return chk;
    }
};