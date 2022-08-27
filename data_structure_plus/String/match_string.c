/*************************************************************************
	> File Name: KMP.c
	> Author: 
	> Mail: 
	> Created Time: Tue 24 May 2022 07:13:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define TSET(func, s, t) {\
    printf("%s(%s, %s) = %d\n", #func, s, t, func(s, t));\
}

char s[100], t[100];
int next[100];

int  kmp(const char *s, const char *t) {
    next[0] = -1;
    for (int i = 1, j = -1; t[i]; i++) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j];
        if (t[j + 1] == t[i]) j++;
        next[i] = j;
    }

    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && t[j + 1] != s[i]) j = next[j];
        if (t[j + 1] == s[i]) j++;
        if (t[j + 1] == 0) return i - j;
    }
    return -1;
}

int brute_force(const char *s, const char *t) {
    int flag;
    for (int i = 0; s[i]; i++) {
        flag = 0;
        for (int j = 0; t[j]; j++) {
            if (s[i + j] == t[j]) continue;
            else {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return i;
        } 
    }
    return -1;
}

int sunday(const char *s, const char *t) {
    int len_s = strlen(s), len_t = strlen(t);
    int ind[256];
    for (int i = 0; i < 256; i++) ind[i] = len_t + 1;
    for (int i = 0; t[i]; i++) ind[t[i]] = len_t - i;
    int i = 0;
    while (i + len_t <= len_s) {
        int flag = 1;
        for (int j = 0; t[j]; j++) {
            if (s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
        i += ind[s[i + len_t]]; // 在T中找S的不匹配位置下一个字符是其倒数第几位，S再往后偏移相应位数
    }
    return -1;
}

int shift_and(const char *s, const char *t) {
    int code[256] = {0};
    int n = 0;
    for (int i = 0; t[i]; i++, n++) {
        code[t[i]] |= (1 << i);
    }

    int p = 0;
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & code[s[i]];
        if (p & (1 << (n - 1))) return i - n + 1;
    }
    return -1;
}

int main() {
    while (~scanf("%s%s", s, t)) {
        TSET(brute_force, s, t);
        TSET(kmp, s, t);
        TSET(sunday, s, t);
        TSET(shift_and, s, t);
    }


    return 0;
}
