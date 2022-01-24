class Solution {
public:
    bool detectCapitalUse(string word) 
    {
      int count =0;
       for(int i=0; i<word.size(); i++) {if(word[i]< 97) count++;}
        if(count ==0 || count == word.size()) return true;
        if(count == 1 && word[0] < 97) return true;
        return false;
    }
};