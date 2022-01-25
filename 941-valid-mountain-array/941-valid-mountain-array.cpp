class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        if(is_sorted(arr.begin(), arr.end()))return false;
         if(is_sorted(arr.rbegin(), arr.rend()))return false;
      if(arr.size() < 3){
        return false;
    }
    
    int i = 1;
    while(i < arr.size()){
        if(arr[i] > arr[i-1]){
            i++;
        }else{
            break;
        }
    }
    
    if(i == arr.size() || i == 1){
        false;
    }
    
    while(i < arr.size()){
        if(arr[i-1] > arr[i]){
            i++;
        }else{
            break;
        }
    }
    
    if(i == arr.size()){
        return true;
    }else{
        return false;
    }
    }
};