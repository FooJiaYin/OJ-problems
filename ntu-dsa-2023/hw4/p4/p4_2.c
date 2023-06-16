#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000056
#define MAXM 1000056
#define SIZE 2000
#define PRIME 13441;

typedef struct Node {
    // string in the rotation with minimum lexicographical order
    // Use malloc instead of array to avoid stack overflow
    char* string;
    // hash of the string in the rotation with minimum lexicographical order
    unsigned int hash;
    int count;
    struct Node* next;
} Node;

/* Convert a string to its rotation with minimum lexicographical order */
void toMinRotation(char string[]) {
    int len = strlen(string);

    // Find minPos, the start position of the rotation with minimum
    // lexicographical order
    int minPos = 0;
    for (int i = 1; i < len; i++) {  // O(M)
        if (string[i] < string[minPos])
            minPos = i;
        else if (string[i] == string[minPos]) {
            int j = (i + 1) % len;
            int k = (minPos + 1) % len;
            while (string[j] == string[k] && j != i) {
                j = (j + 1) % len;
                k = (k + 1) % len;
            }
            // Example: [i..j] = aba, [minPos..k] = abc
            if (string[j] < string[minPos]) {
                minPos = j;
                i = j;
            }
            // Example: [i..j] = abb, [minPos..k] = abc
            else if (string[j] < string[k]) 
                minPos = i;

            // Skip the characters that have been checked
            // to keep time complexity in O(M)
            else if (i < j) i = j;
        }
    }
    // Rotate the string to [minPos...len-1, 0...minPos-1]
    char temp[len + 1];
    strcpy(temp, string + minPos);
    strncat(temp, string, minPos);
    strcpy(string, temp);
}

/* Get the Robin Karp hash of a string
    hash = (s[0] * 26^(n-1) + s[1] * 26^(n-2) + ... + s[n-1]) % prime
    Return same hash if the string is exactly the same as another string */
unsigned calculateHash(char string[]) {
    int len = strlen(string);
    unsigned hash = 0;
    for (int i = 0; i < len; i++) {  // O(M)
        hash *= 26;
        hash += string[i] - 'a';
        hash %= PRIME;
    }
    return hash;
}

/* Create a new node */
Node* newNode(char string[], unsigned long hash) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->hash = hash;
    node->string = (char*)malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(node->string, string);
    node->count = 1;
    node->next = NULL;
    return node;
}

void insertString(Node** hashTable, unsigned long long* rotationCount,
                  char string[]) {
    toMinRotation(string);
    unsigned hash = calculateHash(string);
    int index = hash % SIZE;

    // Check if the node is already in the hashTable
    Node* target = hashTable[index];
    if (target == NULL) {
        // If bucket is empty, add to the bucket
        hashTable[index] = newNode(string, hash);
        return;
    }
    while (target != NULL) {
        if (target->hash == hash) {
            // If found same hash, check if the string is the same
            if (strcmp(string, target->string) == 0) {
                // If same, increase count
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

void removeString(Node** hashTable, unsigned long long* rotationCount,
                  char string[]) {
    toMinRotation(string);
    unsigned long hash = calculateHash(string);
    int index = hash % SIZE;

    // Check if the node is already in the bucket
    Node* target = hashTable[index];
    while (target) {
        if (target->hash == hash) {
            // If found same hash, check if the string is the same
            if (strcmp(string, target->string) == 0) {
                // If same, decrease count
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

/* Print hashTable in the format:
    rotationCount [bucket1] string1 count1 string2 count2 [bucket2] string3
   count3 ... */
void printHashTable(Node** hashTable, unsigned long long rotationCount) {
    printf("%llu ", rotationCount);
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
            free(target->string);
            target = target->next;
            free(temp);
        }
    }
}

int main() {
    Node* hashTable[SIZE] = {NULL};

    int n, q;
    scanf("%d %d", &n, &q);

    // Rotation count = nC2
    unsigned long long rotationCount = 0;

    for (int i = 0; i < n; i++) {
        char str[MAXM];
        scanf("%s", str);
        insertString(hashTable, &rotationCount, str);
        // printHashTable(hashTable, rotationCount);
    }
    // printHashTable(hashTable, rotationCount);
    printf("%llu\n", rotationCount);

    int p;
    for (int i = 0; i < q; i++) {
        char str[MAXM];
        scanf("%d %s", &p, str);
        if (p == 1)
            insertString(hashTable, &rotationCount, str);
        else
            removeString(hashTable, &rotationCount, str);
        // printHashTable(hashTable, rotationCount);
        printf("%llu\n", rotationCount);
    }

    destroyHashTable(hashTable);

    return 0;
}