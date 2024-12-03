#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>
//躺着无聊 刷手机走神 想实现自己脑中的汉诺塔 控制台3数组表示3根柱子 于是有了下面的代码
//整个过程 有点意思 在内心发现了一点平静和其他有意思的东西，但不会写在这 ：）
#define MAX_DISK 30  

void moveDisk(int from[], int to[], int* fromTop, int* toTop) { 
    int disk = from[--(*fromTop)];   
    from[(*fromTop)] = 0;//from[--(*fromTop)] = 0; 内存越界
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
        a[i] = 0;//不设置0 内存数据是乱的 也是为了上面的函数 打印数组时不显示0
    }
}
void hanoi(int n, int source[], int target[], int auxiliary[], int* sourceTop, int* targetTop, int* auxiliaryTop, int* s, int* t, int* a) {
    //int* s, int* t, int* a 这3函数参数 在这的原因是因为 打印3个数组时 跳得很 ：）因为是用的后面的代码  disArray(source, 'S');disArray(target, 'T');disArray(auxiliary, 'A');
    //边刷手机边想如何解决这个问题？我要不要 二层for循环对比前面3数组source target auxiliary和后面s t a 三数组的内存值 解决这个问题？
    //然后我灵机一动 直接改了3处解决这个问题 就是修改 disArray(source, 'S');disArray(target, 'T');disArray(auxiliary, 'A') 为disArray(s, 'S');disArray(t, 'T');disArray(a, 'A');
    //先修改然后直接运行 就解决了问题 脑子都没反应过来 当时是想为什么我不直接改 就完事了 搞这么复杂
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
        Sleep(200); system("cls");
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
    disArray(source, 'S');
    disArray(target, 'T');
    disArray(auxiliary, 'A');
    return 0;
}