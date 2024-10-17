class Solution {
public:
    int maximumSwap(int num) {
        if(num<=11)
            return num;

        // creating bucket
        vector<vector<int>> arr(10);
        string s = to_string(num);

        // filling bucket from back 
        // consider this case : 98368
        for(int i=s.size()-1;i>=0;i--)
        {
           arr[s[i]-'0'].push_back(i);
        }

        int ind=0;
        for(int i=9;i>=0;i--)
        {
            while(!arr[i].empty())
            {
                if((s[ind]-'0') == i){
                    ind++;
                    arr[i].pop_back();
                }
                else
                {
                    swap(s[ind],s[arr[i].front()]);
                    return stoi(s);
                }
            }
        }

        return stoi(s);




























        // vector<pair<char,int>> arr;
        // string s=to_string(num);
        // int first=s[0]-'0';
        // int i=0;
        // for(char c:s)
        //     arr.push_back({c,i++});
        // sort(arr.begin(),arr.end(),cmp);

        // for(int i=0;i<s.size();i++)
        // {
        //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
        //     // condition met
        //     if(!(s[i] == arr[i].first))
        //     {
        //         swap(s[i],s[arr[i].second]);
        //         // break;
        //     }
        // }

        // return stoi(s);
    }
};