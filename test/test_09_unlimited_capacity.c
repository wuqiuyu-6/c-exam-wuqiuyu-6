#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

static int tests_passed = 0;
static int tests_failed = 0;

#define TEST_ASSERT_EQUAL(expected, actual, line) \
    do { \
        if ((expected) == (actual)) { \
            tests_passed++; \
            printf("  [PASS] %s:%d\n", __FILE__, line); \
        } else { \
            tests_failed++; \
            printf("  [FAIL] %s:%d: expected %d, got %d\n", __FILE__, line, (expected), (actual)); \
        } \
    } while(0)

#define TEST_ASSERT_TRUE(condition, line) \
    do { \
        if (condition) { \
            tests_passed++; \
            printf("  [PASS] %s:%d\n", __FILE__, line); \
        } else { \
            tests_failed++; \
            printf("  [FAIL] %s:%d: expected true, got false\n", __FILE__, line); \
        } \
    } while(0)

int main(void) {
    printf("========================================\n");
    printf("   Test 9: Unlimited Capacity\n");
    printf("========================================\n\n");

    Queue* q = queue_create(0);

    // 连续入队1000个元素
    for (int i = 0; i < 1000; i++) {
        TEST_ASSERT_TRUE(queue_enqueue(q, i), __LINE__);
    }
    TEST_ASSERT_EQUAL(1000, (int)queue_size(q), __LINE__);

    // 连续出队
    for (int i = 0; i < 1000; i++) {
        int value;
        TEST_ASSERT_TRUE(queue_dequeue(q, &value), __LINE__);
        TEST_ASSERT_EQUAL(i, value, __LINE__);
    }

    TEST_ASSERT_TRUE(queue_is_empty(q), __LINE__);

    queue_destroy(&q);

    printf("\n========================================\n");
    printf("   Results: %d passed, %d failed\n", tests_passed, tests_failed);
    printf("========================================\n");

    return tests_failed > 0 ? 1 : 0;
}
