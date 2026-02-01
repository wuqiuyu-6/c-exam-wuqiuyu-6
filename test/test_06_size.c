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
    printf("   Test 6: Queue Size\n");
    printf("========================================\n\n");

    Queue* q = queue_create(0);

    TEST_ASSERT_EQUAL(0, (int)queue_size(q), __LINE__);

    queue_enqueue(q, 1);
    TEST_ASSERT_EQUAL(1, (int)queue_size(q), __LINE__);

    queue_enqueue(q, 2);
    queue_enqueue(q, 3);
    TEST_ASSERT_EQUAL(3, (int)queue_size(q), __LINE__);

    queue_dequeue(q, NULL);
    TEST_ASSERT_EQUAL(2, (int)queue_size(q), __LINE__);

    queue_dequeue(q, NULL);
    queue_dequeue(q, NULL);
    TEST_ASSERT_EQUAL(0, (int)queue_size(q), __LINE__);

    queue_destroy(&q);

    printf("\n========================================\n");
    printf("   Results: %d passed, %d failed\n", tests_passed, tests_failed);
    printf("========================================\n");

    return tests_failed > 0 ? 1 : 0;
}
