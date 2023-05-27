// l=0
// 1. find k such S[l:l+n] match P[k:k+n]
// 2. if S[l+n]=P[k+n%n]
//       cnt +1, l++, k++
//    else
//        l++, Go to 1

#include <stdio.h>

int prime = 13441;

// Calculate constant of first position
// firstPos = 26^(n-1) % prime
int getFirstPos(int len) {
    int pos = 1;
    for (int i = 0; i < len - 1; i++) {
        pos *= 26;
        pos %= prime;
    }
    return pos;
}

int initHash(char string[], int len) {
    int hash = 0;
    for (int i = 0; i < len; i++) {
        hash *= 26;
        hash += string[i] - 'A';
        hash %= prime;
    }
    return hash;
}

// Update hash when shift to next window
// hash = hash - (first - 'A') * firstPos + (last - 'A')
int updateHash(int hash, char first, char last, int firstPos) {
    hash -= (first - 'A') * firstPos % prime;
    hash = (hash + prime) % prime;
    hash *= 26;
    hash += (last - 'A');
    hash %= prime;
    return hash;
}

// Find index k such S[l:l+n] match P[k:k+n] with Rabin Karp algorithm
int findK(char S[], char P[], int len, int firstPos, int hashS, int hashP) {
    int k = 0;
    for (int k = 0; k < len; k++) {
        // printf("%d %d\n", hashS, hashP);
        // If hash match, check if string match
        if (hashS == hashP) {
            int i;
            // Break if end of string or mismatch
            for (i = 0; i < len && P[(k + i) % len] == S[i]; i++);
            // If match, return index k
            if (i == len) return k;
        }
        hashP = updateHash(hashP, P[k], P[k], firstPos);
    }
    return -1;
}

int main() {
    char S[] = "DABABBDABDABABDAB";
    char P[] = "ABDAB";
    int l = 0, k = 0;
    int cnt = 0;
    int n = sizeof(P) / sizeof(P[0]) - 1;
    int m = sizeof(S) / sizeof(S[0]) - 1;

    int firstPost = getFirstPos(n) % prime;
    int hashS = initHash(S, n);
    int hashP = initHash(P, n);

    while (l + n < m) {
        k = findK(&S[l], P, n, firstPost, hashS, hashP);
        if (k != -1) {
            // While next char of S and P match
            while (S[l + n - 1] != -1 && S[l + n - 1] == P[(k + n - 1) % n]) {
                cnt++;
                l++;
                k = (k + 1) % n;
                hashS = updateHash(hashS, S[l - 1], S[l + n - 1], firstPost);
            }
        } else {
            l++;
            hashS = updateHash(hashS, S[l - 1], S[l + n - 1], firstPost);
        }
    }
    printf("%d\n", cnt);
    return 0;
}