class Solution {
public:
    int myAtoi(string s) {
        long ans=0; int n=s.size(),i=0;
        bool isPos=true;

        // trim leading whitespaces
        while(i<n && s[i]==' ')
            i++;

        // check sign of number after whitespaces
        if(s[i]=='-'){
            isPos=false;
            i++;
        }else if(s[i]=='+'){
            i++;
        }
        
        while(i<n)
        {
            int num=s[i]-'0';
            if(num>=0 && num<=9){
                ans = ans*10 + num;
                // exceeding max values
                if(ans>INT_MAX)
                {
                    return isPos ? INT_MAX : INT_MIN; 
                }
            }
            else
            {
                // non-digit value encountered
                if(ans && isPos==false)
                    return -1*ans;
                else
                    return ans;
            }
            i++;
        }

        return isPos ? ans :-1*ans;
    }
};