#include <stdio.h>
#include "queue.h"

// 1 x → queue_enqueue(q, x)
// 2 → 先判空，若空输出 ERR_CANNOT_POP，否则 queue_dequeue(q, NULL)
// 3 → 先判空，若空输出 ERR_CANNOT_QUERY，否则输出 queue_front(q)
// 4 → 输出 queue_size(q)，注意使用 %zu 匹配 size_t 类型

int main(void) {
    int n;
    scanf("%d", &n);

    // 创建无容量限制的队列
    Queue* q = queue_create(0);
    if (q == NULL) {
        return 1;  // 内存分配失败
    }

    while (n--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            // push x
            int x;
            scanf("%d", &x);
            queue_enqueue(q, x);
        }
        else if (op == 2) {
            // pop
            if (queue_is_empty(q)) {
                printf("ERR_CANNOT_POP\n\n");  // 错误信息 + 空行
            }
            else {
                queue_dequeue(q, NULL);  // 成功时不输出
            }
        }
        else if (op == 3) {
            // query
            if (queue_is_empty(q)) {
                printf("ERR_CANNOT_QUERY\n\n");  // 错误信息 + 空行
            }
            else {
                printf("%d\n\n", queue_front(q));  // 队首值 + 空行
            }
        }
        else if (op == 4) {
            // size
            printf("%zu\n\n", queue_size(q));  // 大小 + 空行
        }
    }

    queue_destroy(&q);
    return 0;
}