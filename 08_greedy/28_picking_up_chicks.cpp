/*
    link: https://www.spoj.com/problems/GCJ101BB/

    video: https://youtu.be/vrRWIbhGK7o
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    long long int t, j;
    cin >> t;
    for (j = 1;j <= t;++j)
    {
        long long int n, k, b, time;
        cin >> n >> k >> b >> time;

        long long int x[n], v[n], i;
        for (i = 0;i < n;++i)
            cin >> x[i];

        for (i = 0;i < n;++i)
            cin >> v[i];

        int possible = 0, swaps = 0, notpossible = 0;
        for (i = n - 1;i >= 0;--i)
        {
            int distance_needed = b - x[i];
            int distance_possible = v[i] * time;

            // chick will be able to reach barn
            if (distance_possible >= distance_needed)
            {
                possible++;
                // if (notpossible > 0)
                swaps += notpossible;
            }
            // chick will not be able to reach
            else
                // hence notpossible increases
                notpossible++;

            if (possible >= k)
                break;
        }

        if (possible >= k)
            cout << "Case #" << j << ": " << swaps << endl;

        else
            cout << "Case #" << j << ": " << "IMPOSSIBLE" << endl;
    }
    return 0;
}
