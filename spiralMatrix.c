
#include <stdio.h>

    int main()
    {
        int n, a = 0, b = 0, z = 0, num = 0, end = 0;
        scanf("%d", &n);
        int mat[n][n], dar[n*n], c = n, d = n;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &mat[i][j]);
            }
        }
        while (a < c && b < d)
        {
            for (int i = b; i < d; ++i, ++z) {
                dar[z] = mat[a][i];
            }
            a++;
            for (int i = a; i < c; ++i, ++z) {
                dar[z] = mat[i][d - 1];
            }
            d--;
            if (a < c) {
                for (int i = d - 1; i >= b; --i, ++z) {
                    dar[z] = mat[c - 1][i];
                }
                c--;
            }
            if (b < d) {
                for (int i = c - 1; i >= a; --i, ++z) {
                    dar[z] = mat[i][b];
                }
                b++;
            }
        }

        for (int i = 0; i < z; ++i) {
            num += dar[i];
            int l = 0, h = num, mid;

            while(l < h) {
                mid = (l + h) / 2;
                if (num == 1) {
                    end++;
                    break;
                }
                if(mid*mid == num) {
                    end++;
                    break;
                }
                if(mid*mid > num)
                    h = mid;
                else if(mid*mid < num)
                    l = mid+1;
            }
        }

        printf("%d", end);
    }