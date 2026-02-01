#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* ============================================
 * 队列数据结构定义 (仅供参考)
 * ============================================ */

//  // 队列节点结构
// typedef struct QueueNode {
//     int data;                   // 数据域（可根据需要修改为其他类型）
//     struct QueueNode* next;     // 指针域，指向下一个节点
// } QueueNode;

// // 队列主结构
// typedef struct {
//     QueueNode* front;           // 队首指针（出队端）
//     QueueNode* rear;            // 队尾指针（入队端）
//     size_t size;                // 当前队列元素个数
//     size_t capacity;            // 最大容量（可选，0表示无限制）
// } Queue;

typedef struct Queue Queue;

/* ============================================
 * 核心操作函数声明
 * ============================================
*/

/**
 * 创建空队列
 * @param capacity 最大容量，传入0表示无容量限制
 * @return 初始化好的队列指针，失败返回NULL
 * @time_complexity O(1)
 * @space_complexity O(1)
 */
Queue* queue_create(size_t capacity);

/**
 * 销毁队列，释放所有内存
 * @param q 队列指针，执行后指针会被置为NULL（二级指针）
 * @time_complexity O(n)，n为队列当前元素个数
 */
void queue_destroy(Queue** q);

/**
 * 入队操作
 * @param q 队列指针
 * @param value 要入队的值
 * @return 成功返回true，失败（如满队或内存不足）返回false
 * @time_complexity O(1)
 */
bool queue_enqueue(Queue* q, int value);

/**
 * 出队操作
 * @param q 队列指针
 * @param out_value 输出参数，用于接收出队元素的值（可为NULL）
 * @return 成功返回true，空队返回false
 * @time_complexity O(1)
 */
bool queue_dequeue(Queue* q, int* out_value);

/**
 * 查看队首元素（不出队）
 * @param q 队列指针
 * @return 队首元素值，空队行为未定义（调用前应先判空）
 * @time_complexity O(1)
 */
int queue_front(const Queue* q);

/**
 * 查看队尾元素
 * @param q 队列指针
 * @return 队尾元素值，空队行为未定义
 * @time_complexity O(1)
 */
int queue_back(const Queue* q);

/**
 * 检查队列是否为空
 * @param q 队列指针
 * @return 空队返回true，否则false
 * @time_complexity O(1)
 */
bool queue_is_empty(const Queue* q);

/**
 * 检查队列是否已满（针对有容量限制的情况）
 * @param q 队列指针
 * @return 已满返回true，否则false（无容量限制时永远返回false）
 * @time_complexity O(1)
 */
bool queue_is_full(const Queue* q);

/**
 * 获取队列当前元素个数
 * @param q 队列指针
 * @return 元素个数
 * @time_complexity O(1)
 */
size_t queue_size(const Queue* q);

/**
 * 清空队列（移除所有元素，但不销毁队列本身）
 * @param q 队列指针
 * @time_complexity O(n)
 */
void queue_clear(Queue* q);

#endif /* QUEUE_H */