/*
    link: https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#

    sol: https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/
*/


int countRev (string s)
{
    int n = s.length();
    if(n % 2)
    {
        return -1;
    }
    
    int ans = 0;
    int opening = 0, closing = 0;
    for(int i = 0;i<n;i++)
    {
        if(s[i] == '{') opening++;
        else closing++;
        
        if(closing > opening)
        {
            ans += closing - opening;
            swap(closing, opening);
        }
    }
    ans += (abs(closing - opening))/2;
    return ans;
}


/*
TC O(n)
SC O(1)
*/

int countRev (string s)
{
    // if length is odd, we can't balance
    if (s.length () & 1) return -1;
    
    // number of opening and closing braces
    int op = 0, cl = 0;

    int res = 0; // ans
    for (int i = 0; i < s.length (); ++i)
    {
        if (s[i] == '{') op++;
        else cl++;
    
        // if cl exceeds op, then we balance the brackets till that point
        if (cl > op)
        {
            res += cl - op;
            swap (cl, op);
        }
    }
    
    
    // finally, the we reverse the half of brakcets that form the unbalance
    // to balance the unbalanced pairs
    res += (abs (cl - op)) / 2;
    return res;
}


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(n)
    SC: O(n)
*/
int countMinReversals(string str)
{
    int len = str.length();

    // length of expression must be even to make
    // it balanced by using reversals.
    if (len % 2)
        return -1;

        // After this loop, stack contains unbalanced
        // part of expression, i.e., expression of the
        // form "}}..}{{..{"
    stack<char> stck;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '}' && !stck.empty())
        {
            if (stck.top() == '{')
                stck.pop();
            else
                stck.push(str[i]);
        }
        else
            stck.push(str[i]);
    }

    // Length of the reduced expression stack_len = (m+n)
    int stack_len = stck.size();

    // count opening brackets at the end of stack
    int left = 0, right;
    while (!stck.empty() && stck.top() == '{')
    {
        stck.pop();
        left++;
    }

    // return ceil(m/2) + ceil(left/2) which is
    // actually equal to (m+left)/2 + left%2 when m+left is even.

    /*
        why ceil of both left and right?

        trace code for 2 eg. :
        1. }}}{
            ceil(3.0/2) + ceil(1.0/2)   here manually change brackets
        2. }}}}{{
            ceil(4.0/2) + ceil(2.0/2)   here manually change brackets
    */
    right = stack_len - left;
    return ceil((long double)right / 2) + ceil((long double)left / 2);
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(n)
    SC: O(1)
*/
int countRev(string s)
{
    int len = s.length();
    int left = 0, right = 0;

    // Expressions of odd lengths cannot be balanced
    if (len % 2)
        return -1;



    for (int i = 0; i < len; i++)
    {
        // If we find a left bracket then we simply increment the left bracket
        if (s[i] == '{')
        {
            left++;
        }
        // Else if left bracket is 0 then we find unbalanced right bracket and increment
        // right bracket or if the expression is balanced then we decrement left
        else {
            if (left == 0) right++;
            else left--;
        }
    }

    return ceil((long double)right / 2) + ceil((long double)left / 2);
}