#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// 队列节点结构
typedef struct QueueNode {
    int data;               // 数据域
    struct QueueNode* next; // 指向下一个节点的指针
} QueueNode;

// 队列主结构
struct Queue {
    QueueNode* front;    // 队首指针
    QueueNode* rear;     // 队尾指针
    size_t size;         // 当前队列大小
    size_t capacity;     // 队列容量（0表示无限制）
};

Queue* queue_create(size_t capacity) {
    // 分配队列结构内存
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        return NULL;  // 内存分配失败
    }
    
    // 初始化队列属性
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    q->capacity = capacity;
    
    return q;
}

void queue_destroy(Queue** q) {
    if (q == NULL || *q == NULL) {
        return;  // 空指针检查
    }
    
    // 清空队列中的所有节点
    queue_clear(*q);
    
    // 释放队列结构
    free(*q);
    *q = NULL;  // 将指针设为NULL防止野指针
}

bool queue_enqueue(Queue* q, int value) {
    if (q == NULL) {
        return false;  // 队列指针为空
    }
    
    // 检查队列是否已满（仅在设置了容量限制时）
    if (queue_is_full(q)) {
        return false;  // 队列已满，无法入队
    }
    
    // 创建新节点
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        return false;  // 内存分配失败
    }
    
    // 初始化新节点
    new_node->data = value;
    new_node->next = NULL;
    
    // 将新节点加入队列
    if (queue_is_empty(q)) {
        // 队列为空，新节点既是队首也是队尾
        q->front = new_node;
        q->rear = new_node;
    } else {
        // 队列不为空，将新节点连接到队尾
        q->rear->next = new_node;
        q->rear = new_node;
    }
    
    // 更新队列大小
    q->size++;
    return true;  // 入队成功
}

bool queue_dequeue(Queue* q, int* out_value) {
    if (q == NULL || queue_is_empty(q)) {
        return false;  // 队列为空或指针为空
    }
    
    // 获取队首节点
    QueueNode* front_node = q->front;
    
    // 如果out_value指针不为NULL，保存出队的值
    if (out_value != NULL) {
        *out_value = front_node->data;
    }
    
    // 更新队首指针
    q->front = front_node->next;
    
    // 如果队列变为空，更新队尾指针
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    // 释放原队首节点内存
    free(front_node);
    
    // 更新队列大小
    q->size--;
    return true;  // 出队成功
}

int queue_front(const Queue* q) {
    // 根据头文件说明，调用此函数前应先判空
    // 空队行为未定义，但我们仍返回0作为安全值
    if (q == NULL || queue_is_empty(q)) {
        return 0;
    }
    
    return q->front->data;
}

int queue_back(const Queue* q) {
    // 根据头文件说明，调用此函数前应先判空
    // 空队行为未定义，但我们仍返回0作为安全值
    if (q == NULL || queue_is_empty(q)) {
        return 0;
    }
    
    return q->rear->data;
}

bool queue_is_empty(const Queue* q) {
    if (q == NULL) {
        return true;  // 空指针视为空队列
    }
    
    return (q->size == 0);
}

bool queue_is_full(const Queue* q) {
    if (q == NULL) {
        return true;  // 空指针视为已满
    }
    
    // 如果capacity为0，表示无容量限制，永远不会满
    if (q->capacity == 0) {
        return false;
    }
    
    return (q->size >= q->capacity);
}

size_t queue_size(const Queue* q) {
    if (q == NULL) {
        return 0;  // 空指针返回0
    }
    
    return q->size;
}

void queue_clear(Queue* q) {
    if (q == NULL) {
        return;  // 队列指针为空
    }
    
    // 循环释放所有节点
    int temp;
    while (!queue_is_empty(q)) {
        queue_dequeue(q, &temp);
    }
}