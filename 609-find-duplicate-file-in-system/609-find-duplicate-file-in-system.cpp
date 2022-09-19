class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) 
    {
       int n = paths.size();
        map<string, vector<string>>mp;
        
        for(int i=0; i<n; i++)
        {
            string s = paths[i];
            
            stringstream X(s);
            
            string dr, drName;
            bool flag = true;
            
            while(getline(X, dr, ' '))
            {
                if(flag)
                {
                    drName = dr;
                    flag = false;
                }
                else
                {
                    int len1=0 , p = 0;
                    while(p < dr.size() && dr[p++] != '(') len1++;
                    string fileName = dr.substr(0, len1);
                    
                    int len2 = 0, q = len1+1;
                    
                    while(q < dr.size() && dr[q++] != ')') len2++;
                    
                    string fileContent = dr.substr(len1 + 1, len2);
                    mp[fileContent].push_back(drName + "/" + fileName);
                }
            }
        }
        vector<vector<string>>ans;
        for (auto &[content, directoryAndFile] : mp) {
            if(directoryAndFile.size() == 1) continue;
            ans.push_back(directoryAndFile);
        }
        
        return ans;
    }
};