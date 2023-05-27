// l=0
// 1. find k such S[l:l+n] match P[k:k+n]
// 2. if S[l+n]=P[k+n%n]
//       cnt +1, l++, k++
//    else
//        l++, Go to 1

#include <stdio.h>

int prime = 13441;

int getFirstPos(int len) {
    int pos = 1;
    for (int i = 0; i < len - 1; i++) {
        pos *= 26;
        pos %= prime;
    }
    return pos;
}

int calculateHash(char string[], int len) {
    int hash = 0;
    for (int i = 0; i < len; i++) {
        hash *= 26;
        hash += string[i] - 'A';
        hash %= prime;
    }
    return hash;
}

// Find index k such S[l:l+n] match P[k:k+n] with Rabin Karp algorithm
int findK(char S[], char P[], int len, int firstPos) {
    int k = 0;
    int hashS = calculateHash(S, len);
    int hashP = calculateHash(P, len);
    // printf("%d %d\n", hashS, hashP);
    for (int k = 0; k < len; k++) {
        if (hashS == hashP) {
            int i;
            for (i = 0; i < len && P[(k + i) % len] == S[i]; i++);
            if (i == len) return k;
        }
        hashP -= (P[k] - 'A') * firstPos % prime;
        hashP = (hashP + prime) % prime;
        hashP *= 26;
        hashP += (P[k] - 'A');
        hashP %= prime;
    }
    return -1;
}

int main() {
    char S[] = "DEABCDE";
    char P[] = "ABCDE";
    int l = 0, k = 0;
    int cnt = 0;
    int n = sizeof(P) / sizeof(P[0]) - 1;
    int m = sizeof(S) / sizeof(S[0]) - 1;
    int firstPost = getFirstPos(n) % prime;
    while (l + n < m) {
        k = findK(&S[l], P, n, firstPost);
        if (k != -1) {
            while (S[l + n - 1] != -1 && S[l + n - 1] == P[(k + n - 1) % n]) {
                // printf("%d%c%d ", l, S[l], k);
                cnt++;
                l++;
                k = (k + 1) % n;
            }
        } else {
            l++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}