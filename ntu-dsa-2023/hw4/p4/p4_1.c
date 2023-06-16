#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000056
#define MAXM 1000056
#define SIZE 20
#define PRIME 13441;
#define PRIME2 13441 * 13441;

typedef struct Node {
    char string[MAXM];
    // A string and its rotation have the same rotationHash
    unsigned long rotationHash;
    // Same if two strings are exactly the same
    unsigned int stringHash;
    // used to update hash, 26^(len-1) % prime
    unsigned int firstPos;
    int count;
    struct Node* next;
} Node;

/* Get the rotation hash of a string 
    Return same hash if the string is a rotation of another string */
unsigned long getRotationHash(char string[]) {
    int primes[26] = {1,  2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,
                      41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    unsigned long hash = 0;
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        unsigned hash1 = primes[string[i] - 'a'];
        unsigned hash2 = primes[string[(i + 1) % len] - 'a'];
        // hash += (string[i] - 'a') * (string[(i + 1) % len] - 'a');
        hash += hash1 * hash2;
        // hash += hash1 * hash1 * hash2;
        // printf("%d %d %d\n", hash1, hash2, hash);
        hash %= PRIME2;
    }
    return hash;
}

/* Get the string hash of a string 
    Return same hash if the string is exactly the same as another string */
unsigned getStringHash(char string[]) {
    int len = strlen(string);
    unsigned hash = 0;
    for (int i = 0; i < len; i++) {
        hash *= 26;
        hash += string[i] - 'a';
        hash %= PRIME;
    }
    return hash;
}

/* Calculate constant of first position
    firstPos = 26^(n-1) % prime */
unsigned getFirstPos(int len) {
    unsigned firstPos = 1;
    for (int i = 0; i < len - 1; i++) {
        firstPos *= 26;
        firstPos %= PRIME;
    }
    return firstPos;
}

/* Update hash when shift to next window
    hash = hash * 26 + (last - 'a') */
int updateHash(int hash, char first, int firstPos) {
    hash -= (first - 'a') * firstPos % PRIME;
    hash += PRIME;
    hash %= PRIME;
    hash *= 26;
    hash += (first - 'a');
    hash %= PRIME;
    return hash;
}

/* Check if string is rotation of target */
int isRotation(char string[], Node* target) {
    // Check if the length match
    int len = strlen(string);
    if (len != strlen(target->string)) {
        return 0;
    }

    // Calculate hash of the string
    unsigned hash = getStringHash(string);
    if (target->firstPos == 0) {
        target->stringHash = getStringHash(target->string);
        target->firstPos = getFirstPos(len);
    }

    int k = 0;
    for (k = 0; k < len; k++) {
        // If hash match, check if string match
        if (hash == target->stringHash) {
            int i;
            // Break if end of string or mismatch
            for (i = 0; i < len && string[(k + i) % len] == target->string[i];
                 i++);
            // If match, return true
            if (i == len) return 1;
        }
        hash = updateHash(hash, string[k], target->firstPos);
    }
    return 0;
}

/* Create a new node */
Node* newNode(char string[], unsigned long hash) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->rotationHash = hash;
    node->firstPos = 0;
    strcpy(node->string, string);
    node->count = 1;
    node->next = NULL;
    return node;
}

void insertString(Node** hashTable, unsigned* rotationCount, char string[]) {
    unsigned long hash = getRotationHash(string);
    int index = hash % SIZE;

    // Check if the node is already in the hashTable
    Node* target = hashTable[index];
    if (target == NULL) {
        // If bucket is empty, add to the bucket
        hashTable[index] = newNode(string, hash);
        return;
    }
    while (target != NULL) {
        if (target->rotationHash == hash) {
            // If found same rotationHash, check if the string is rotation
            if (isRotation(string, target)) {
                // If is rotation, increase count
                *rotationCount += target->count;
                target->count++;
                return;
            }
        }
        if (target->next == NULL) break;
        target = target->next;
    }
    // If not found, add to the end of the bucket
    target->next = newNode(string, hash);
    return;
}

void removeString(Node** hashTable, unsigned* rotationCount, char string[]) {
    unsigned long hash = getRotationHash(string);
    int index = hash % SIZE;

    // Check if the node is already in the bucket
    Node* target = hashTable[index];
    while (target) {
        if (target->rotationHash == hash) {
            // If found same rotationHash, check if the string is rotation
            if (isRotation(string, target)) {
                // If is rotation, decrease count
                target->count--;
                *rotationCount -= target->count;
                return;
            }
        }
        if (target->next == NULL) break;
        target = target->next;
    }
    return;
}

void printHashTable(Node** hashTable, unsigned rotationCount) {
    printf("%u ", rotationCount);
    for (int i = 0; i < SIZE; i++) {
        printf("[%d] ", i);
        if (hashTable[i] == NULL) continue;
        Node* target = hashTable[i];
        while (target) {
            printf("%s %d ", target->string, target->count);
            target = target->next;
        }
    }
    printf("\n");
}

void destroyHashTable(Node** hashTable) {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == NULL) continue;
        Node* target = hashTable[i];
        while (target) {
            Node* temp = target;
            target = target->next;
            free(temp);
        }
    }
}

int main() {
    Node* hashTable[SIZE] = {NULL};
    
    int n, q;
    unsigned long hash;
    scanf("%d %d", &n, &q);

    // Rotation count = nC2
    unsigned rotationCount = 0;

    for (int i = 0; i < n; i++) {
        char str[MAXM];
        scanf("%s", str);
        insertString(hashTable, &rotationCount, str);
        // printHashTable(hashTable, rotationCount);
    }
    printf("%u\n", rotationCount);

    int p;
    for (int i = 0; i < q; i++) {
        char str[MAXM];
        scanf("%d %s", &p, str);
        if (p == 1)
            insertString(hashTable, &rotationCount, str);
        else
            removeString(hashTable, &rotationCount, str);
        // printHashTable(hashTable, rotationCount);
        printf("%d\n", rotationCount);
    }

    destroyHashTable(hashTable);

    return 0;
}