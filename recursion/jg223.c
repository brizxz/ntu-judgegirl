#include <stdio.h>
 
int dx[] = {1, 1, -1, -1};
int dy[] = {-1, 1, 1, -1};
 
void printL(int cx, int cy, int size, int type)
{
    if (size == 2)
        printf("%d %d %d\n", type, cx, cy);
    else {
        printL(cx, cy, size / 2, type);
        printL(cx + dx[(type + 1) % 4] * size / 4, cy + dy[(type + 1) % 4] * size / 4, size / 2, (type + 2) % 4 + 1);
        printL(cx + dx[(type + 2) % 4] * size / 4, cy + dy[(type + 2) % 4] * size / 4, size / 2, (type + 3) % 4 + 1);
        printL(cx + dx[(type + 3) % 4] * size / 4, cy + dy[(type + 3) % 4] * size / 4, size / 2, (type + 4) % 4 + 1);
    }
    return;
}
 
int main(void)
{
    int l, m;
    scanf("%d%d", &l, &m);
    for (int c = l / 2; c <= l - m; c = (c + l + 1) / 2)
        printL(c, c, (l - c) * 2, 1);
    return 0;
}