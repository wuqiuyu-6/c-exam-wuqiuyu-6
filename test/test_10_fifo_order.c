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
    printf("   Test 10: FIFO Order\n");
    printf("========================================\n\n");

    Queue* q = queue_create(0);

    int test_values[] = {5, 10, 15, 20, 25};
    for (int i = 0; i < 5; i++) {
        queue_enqueue(q, test_values[i]);
    }

    for (int i = 0; i < 5; i++) {
        int value;
        queue_dequeue(q, &value);
        TEST_ASSERT_EQUAL(test_values[i], value, __LINE__);
    }

    queue_destroy(&q);

    printf("\n========================================\n");
    printf("   Results: %d passed, %d failed\n", tests_passed, tests_failed);
    printf("========================================\n");

    return tests_failed > 0 ? 1 : 0;
}
