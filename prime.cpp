//
// Created by ZGD on 2019/7/31.
//

// 找出孪生素数的个数
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int a[500000];   // 记录素数
    int m = 1, last_n = 2;
    a[0] = 2;
    while (scanf("%d", &n) != EOF) {
        if (last_n < n) { // 更新素数序列
            for (int s = last_n + 1; s <= n; s++) {
                int i, is_prime=1;
                for (i = 0; i < m && a[i] <= (int)sqrt(s); i++) {
                    if (s % a[i] == 0) {
                        is_prime = 0;
                        break;
                    }
                }
                if (is_prime == 1) {// s为素数
                    a[m++] = s;
                }
            }
            last_n = n;
        }
        int count = 0, i=0;
        while(i<m-1 && a[i+1] <= n) {
            if (a[i] + 2 == a[i+1]) {
                count++;
//                printf("%d (%d,%d)\n", count, a[i], a[i+1]);
            }
            i++;
        }
        printf("%d\n", count);
    }
    return 0;
}
