/*
    link: https://practice.geeksforgeeks.org/problems/word-break1352/1

    ref: 14_DP/55_word_break_problem.cpp
*/


unordered_map<string, int> dp;

int solve(string s, vector<string> &b)
{
    int sz = s.size();

    if(sz == 0)
    {
        return 1; //we have a blank string
    }

    if(dp[s] != 0) return dp[s];

    for(int i = 0;i<=sz;i++)
    {
        int flag = 0;
        string ss = s.substr(0,i);
        for(int j = 0; j < b.size(); j++)
        {
            if(ss == b[j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1 && solve(s.substr(i, sz-i),b) == 1)
        {
            return dp[s] = 1;
        }
    }

    return dp[s] = -1;
}

int wordBreak(string A, vector<string> &B)
{
    int x = solve(A,B);

    if(x == 1) return 1;
    return 0;
}