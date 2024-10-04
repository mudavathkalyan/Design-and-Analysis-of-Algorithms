#include <stdio.h>
#include <string.h>

char a[22];  // Array to store the current permutation

// Function to print the current permutation
void print(char a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%c ", a[i]);
    }
    printf("\n");
}

// Function to check if the character is already used in the current permutation
int isSafe(int pos, char ch, char a[]) {
    for(int j = 0; j < pos; j++) {
        if(a[j] == ch) {
            return 0;
        }
    }
    return 1;
}

// Backtracking function to generate permutations
void back(char input[], int n, int pos) {
    if(n == pos) {
        print(a, n);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(isSafe(pos, input[i], a)) {
            a[pos] = input[i];
            back(input, n, pos + 1);
        }
    }
}

int main() {
    char input[22];
    printf("Enter characters (without spaces): ");
    scanf("%s", input);
    int n = strlen(input);
    back(input, n, 0);
    return 0;
}
