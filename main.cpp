class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> copie(nums);
        int max (0),length (0);
        sort(copie.begin(),copie.end());
        for(auto i =0; i<copie.size()-1;i++){
            if(copie[i] == copie[i+1] -1)
                max++;
            else max = 0;
            if(length<max)
                length =  max;
        }
        if(length)
            return length + 1;
        else return 0;
            
    }
};