/*

link: https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
sol: https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/
video: https://www.youtube.com/watch?v=g6OxU-hRGtY

to find set bits: __builtin_popcount(N);

*/

/*
    The basic idea is to use the formula

    s(n) = (2^(x-1))*x + (n - 2^x + 1) + s(n - 2^x);

    (2^(x-1))*x --> gives the number of bits in a power of 2 just smaller or equal to n
    eg. for n = 11 , this expression will count all the bits upto to 8

    (n - 2^x + 1) --> this is to add all the bits that get added when we move ahead a power of 2
    eg upto 7 we use only 3 bits but from 8 we start using 4 bits

    s(n - 2^x) --> this is to reduce the number by substracting the power of 2 closest to
    the number
*/
int largestPowerOf2(int n)
{
    int x = 0;

    while(1 << x <= n)
    {
        x++;
    }

    return x-1; //this returns the power of 2
}

int countBits(int n)
{
    if(n <= 0) return 0;

    if(n == 1) return 1;

    int x = largestPowerOf2(n);

    return ((1 << x-1) * x) + (n - (1 << x) + 1) + countBits(n - (1 << x));
}

// ----------------------------------------------------------------------------------------------------------------------- //

int total_popcount(int n) {
    int count = 0;
    while (n) {
        if (n & 1) count++;
        n >>= 1;
    }
    return count;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// method 1
// TC: O(N)
int countSetBits(int n)
{
    int count = 0;
    for (int i = 1;i <= n;i++) {
        count += total_popcount(i);
    }
    return count;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// method 2
// TC: O(N log N);
int countSetBits(int n) {
    int i = 0;  // for bit position from least to most significant

    int ans = 0;

    while ((1 << i) <= n) {
        bool k = 0; // temp bit status, will change after certain pos
        int change = 1 << i;
        /* for eg. if bit pos is 0 then it will change alternative and if bit pos is 1 then will change after every 2 occurences. */

        for (int j = 0;j <= n;j++) {
            ans += k;   // save temp bit to ans
            if (change == 1) {
                k = !k;
                change = 1 << i;
            }
            else {
                change--;
            }
        }
        i++;
    }
    return ans;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// method 3 most optimal
// TC: O(log(N))
// refer: onenote for 
int findPower(int n) {
    int count = 0;
    while ((1 << count) <= n) {
        count++;
    }
    return count - 1;
}
int countSetBits(int n)
{
    if (n == 0) {
        return 0;
    }

    int max_pow_of_2 = findPower(n); // or can use log2(n) instead of self made function.
    int till_pow_of_2 = max_pow_of_2 * (1 << (max_pow_of_2 - 1));

    int extra_line_of_bit = n - (1 << max_pow_of_2) + 1;

    return till_pow_of_2 + extra_line_of_bit + countSetBits(n - (1 << max_pow_of_2));
}

// ----------------------------------------------------------------------------------------------------------------------- //