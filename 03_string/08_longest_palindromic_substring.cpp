/*
    link: https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

    for detailed explanation as well as other solutions: DP/31_print_longest...
*/


//TC O(n*n)
//SC O(1)
string longestPalin(string s)
{
    int resStart = -1;
    int resLen = 0;

    int n = s.length();

    for(int i = 0; i < n;i++)
    {
        //for odd length
        int l = i,r = i;

        while(l >= 0 && r < n && s[l] == s[r])
        {
            if((r - l + 1) > resLen)
            {
                resLen = r - l + 1;
                res = l;
            }
            l--;
            r++;
        }



        //for even length
        l = i;
        r = i + 1;

         while(l >= 0 && r < n && s[l] == s[r])
        {
            if((r - l + 1) > resLen)
            {
                resLen = r - l + 1;
                res = l;
            }
            l--;
            r++;
        }
    }

    return s.substr(res, resLen);
}

// ----------------------------------------------------------------------------------------------------------------------- //
string longestPalin(string s)
{
    int low, high, maxLen = 1, start = 0, len = s.size();

    for (int i = 1;i < len;i++) {
        // for even length
        // fixing the point i and i+1.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && s[low] == s[high]) {
            if (high - low + 1 > maxLen) {
                start = low;
                maxLen = high - low + 1;
            }
            low--;
            high++;
        }

        // for odd length 
        // fixing the point i.
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && s[low] == s[high]) {
            if (high - low + 1 > maxLen) {
                start = low;
                maxLen = high - low + 1;
            }
            low--;
            high++;
        }
    }
    return s.substr(start, maxLen);
}