'''
Enter the values of m and n: 7 3
Enter the message: sausage
Original Message: sausage
Encrypted Message: zdnzdtf
Decrypted Message: sausage
'''

#include <stdio.h>
#include <math.h>
#include <string.h>

#define ALPHABET_SIZE 26

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findModularInverse(int a, int m) {
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1) {
            return i;
        }
    }
    return -1;  // No modular inverse exists
}

void encryptDecrypt(char p[], int m, int n, int mode) {
    int x, y;

    for (int i = 0; i < strlen(p) - 1; i++) {
        x = (int)p[i];
        if (x == 32) continue;

        x -= 97;
        if (mode == 0) {
            x = (m * x + n) % ALPHABET_SIZE;
        } else {
            int inverse = findModularInverse(m, ALPHABET_SIZE);
            x = inverse * (x - n);
            while (x < 0) x += ALPHABET_SIZE;
            x = x % ALPHABET_SIZE;
        }

        x += 97;
        p[i] = (char)x;
    }
}

int main() {
    char p[1000];
    int m, n;

    printf("Enter the values of m and n: ");
    scanf("%d %d", &m, &n);

    if (m < 1 || m > ALPHABET_SIZE || findGCD(m, ALPHABET_SIZE) != 1) {
        printf("Invalid value of m. Exiting...\n");
        return 0;
    }

    printf("Enter the message: ");
    fgets(p, sizeof(p), stdin);
    fgets(p, sizeof(p), stdin);

    printf("Original Message: %s", p);

    encryptDecrypt(p, m, n, 0);
    printf("Encrypted Message: %s", p);

    encryptDecrypt(p, m, n, 1);
    printf("Decrypted Message: %s", p);

    return 0;
}