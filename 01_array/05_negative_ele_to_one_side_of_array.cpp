/*
    link: https://www.geeksforgeeks.org/move-negative-numbers-beginning-jtive-end-constant-extra-space/

    variation: 2-pointer
*/


// ----------------------------------------------------------------------------------------------------------------------- //
void arrange(int a[], int n) {
    int i = 0;
    int j = n - 1;

    while (i <= j) {
        if (a[i] < 0 && a[j] < 0) {
            i++;
        }
        else if (a[i] > 0 && a[j] < 0) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        else if (a[i] > 0 && a[j] > 0) j--;
        else {
            i++;
            j--;
        }
    }
}