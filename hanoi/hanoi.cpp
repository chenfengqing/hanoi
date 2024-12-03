#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#define MAX_DISK 30  

void moveDisk(int from[], int to[], int* fromTop, int* toTop) { 
    int disk = from[--(*fromTop)];   
    from[(*fromTop)] = 0;
    to[(*toTop)++] = disk; 
    printf("Move disk:  %d\n", disk);
}
void disArray(int* a, char t) {
    printf("%c:  ", t);
    for (int i = 0; i < MAX_DISK; i++) {
        if (a[i] == 0) { continue; }
        else {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}
void setArray(int* a) {
    for (int i = 0; i < MAX_DISK; i++) {
        a[i] = 0;
    }
}
void hanoi(int n, int source[], int target[], int auxiliary[], int* sourceTop, int* targetTop, int* auxiliaryTop, int* s, int* t, int* a) {

    if (n == 1) {
        moveDisk(source, target, sourceTop, targetTop); system("cls");
    }
    else {
        hanoi(n - 1, source, auxiliary, target, sourceTop, auxiliaryTop, targetTop, s, t, a);
        disArray(s, 'S');
        disArray(t, 'T');
        disArray(a, 'A');
        moveDisk(source, target, sourceTop, targetTop);
        disArray(s, 'S');
        disArray(t, 'T');
        disArray(a, 'A');
        Sleep(3100); system("cls");
        hanoi(n - 1, auxiliary, target, source, auxiliaryTop, targetTop, sourceTop, s, t, a);
    }
}

int main() {
    int n; 
    int source[MAX_DISK], target[MAX_DISK], auxiliary[MAX_DISK];
    int sourceTop = 0, targetTop = 0, auxiliaryTop = 0;
    setArray(source); setArray(target); setArray(auxiliary);
    printf("Enter the number of disks: ");
    scanf_s("%d", &n);

    for (int i = n; i >= 1; i--) {
        source[sourceTop++] = i;   
    }

    hanoi(n, source, target, auxiliary, &sourceTop, &targetTop, &auxiliaryTop, source, target, auxiliary);
    return 0;
}