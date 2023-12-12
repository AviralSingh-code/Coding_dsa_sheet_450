/*
    link: https://practice.geeksforgeeks.org/problems/word-break1352/1

    ref: 14_DP/55_word_break_problem.cpp
*/

//-----------------------------------------------------------------

struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, Node* n)
    {
        links[ch - 'a'] = n;
    }
    
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }
    
    void setFlag()
    {
        flag = true;
    }
    
    bool checkFlag()
    {
        return flag;
    }
};

class Trie{
    private:
    Node* temp;
    public:
    Trie()
    {
        temp = new Node();
    }
    
    void buildTrie(string s)
    {
        Node* node = temp;
        for(int i = 0;i<s.length();i++)
        {
            if(!node->containsKey(s[i]))
            {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->setFlag();
    }
    
    bool containsWord(string s)
    {
        Node* node = temp;
        for(int i = 0;i<s.length();i++)
        {
            if(!node->containsKey(s[i]))
            {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->checkFlag();
    }
    
    bool checkWord(string s)
    {
        int n = s.length();
        
        Node* node = temp;
        for(int i = 0; i < n; i++)
        {
            if(!node->containsKey(s[i]))
            {
                if(node->checkFlag())
                {
                    node = temp;
                    i--;
                    continue;
                }
                else
                {
                    return false;
                }
            }
            
            node = node->get(s[i]);
        }
        
        return true;
    }
};

//-----------------------------------------------------------------
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