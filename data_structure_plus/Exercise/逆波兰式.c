/*************************************************************************
	> File Name: 逆波兰式.c
	> Author: 
	> Mail: 
	> Created Time: Sun 29 May 2022 05:52:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int calu(char *str, int l, int r) {
    int pos = -1 ,temp = 0x3f3f3f3f - 1;
    for (int i = l; i <= r; i++) {
        int cur = 0x3f3f3f3f;
        switch(str[i]) {
            case '+':
            case '-': cur = 1;break;
            case '*':
            case '/': cur = 2;break;
        }
        if (cur <= temp) {
            pos = i;
            temp = cur;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + (str[i] - '0');
        }
        return num;
    }
    int a = calu(str, l, pos - 1);
    int b = calu(str, pos + 1, r);
    switch(str[pos]) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' : return a / b;
    }
    return 0;
}

int main() {
    char str[100];
    scanf("%s", str);
    int ans = calu(str, 0, strlen(str));
    printf("%d\n", ans);
    return 0;
}
