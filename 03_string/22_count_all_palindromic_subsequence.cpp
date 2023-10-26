/*
    link: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

    DP variation

    sol refer to: 14_DP/46_all_count_palindromic_subsequence.cpp

    note: currently sol. is not working in practice.gfg but its correct.
*/

// video link : https://www.youtube.com/watch?v=vlbA8oUxSV0

int func(int i, int j, string s)
{
    if(i > j) return 0;
    if(i == j) return 1;

    if(s[i] == s[j])
    {
        return func(i+1, j, s) + func(i, j-1, s) + 1;
    }
    return func(i+1, j, s) + func(i, j-1, s) - func(i+1, j-1, s);
}


//with memoization

//tc O(n*n) --> max state of dp where n is the length of the string
//sc O(n*n) --> for dp
int func(int i, int j, string s, vector<vector<int>> &dp)
{
    if(i > j) return 0;
    if(i == j) return 1;

    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == s[j])    //for aba type case
    {
        return dp[i][j] =  func(i+1, j, s) + func(i, j-1, s) + 1;
    }
    return dp[i][j] = func(i+1, j, s) + func(i, j-1, s) - func(i+1, j-1, s);  //for abc type case
}