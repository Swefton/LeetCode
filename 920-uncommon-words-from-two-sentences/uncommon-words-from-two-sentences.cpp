class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        cout << s << endl;
        unordered_map<string,int> countTable;
        string tmp="";

        for(auto& val : s)
        { 
            if(val == ' ' )
            {
                countTable[tmp]++;
                tmp = "";
            }
            else{
                tmp += val;
            }
        }

        if(tmp != "")
        {
            countTable[tmp]++;
            tmp = "";
        }
        
        vector<string> uncommonWords;

        for(auto& val : countTable)
        {
            cout << val.first << " " << val.second << endl;

            if(val.second==1)
            {
                uncommonWords.push_back(val.first);               
            }

        }

        return uncommonWords;
    }
};