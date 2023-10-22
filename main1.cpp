class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs[0]=="") return {{""}};
        vector<string> copie(strs), change;
         int n = strs.size();
        for(int i = 0; i<n ; i++){
            change.push_back(copie[i]);
            for(int j = i+1; j<n; j++){
                bool areAnagrams = true;
                if(copie[i].length()!= copie[j].length()) areAnagrams = false;
                else{
                    unordered_map<char,int> s_map,t_map;
                    for(auto letters : copie[i])
                        s_map[letters]++;
                    for(auto letters : copie[j])
                        t_map[letters]++;
                    for(auto& [keys,count] : t_map)
                        if(t_map[keys]!=s_map[keys]) areAnagrams = false;
                    }
                if(areAnagrams){
                    change.push_back(copie[j]);
                    copie.erase(copie.begin() + j);
                    n--;
                    j--;
                }
                
            }
                result.push_back(change);
                change.clear();
        }
        return result;

    }
};