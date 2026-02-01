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

#define TEST_ASSERT_FALSE(condition, line) \
    do { \
        if (!(condition)) { \
            tests_passed++; \
            printf("  [PASS] %s:%d\n", __FILE__, line); \
        } else { \
            tests_failed++; \
            printf("  [FAIL] %s:%d: expected false, got true\n", __FILE__, line); \
        } \
    } while(0)

int main(void) {
    printf("========================================\n");
    printf("   Test 1: Create and Destroy\n");
    printf("========================================\n\n");

    Queue* q = queue_create(0);
    TEST_ASSERT_TRUE(q != NULL, __LINE__);
    queue_destroy(&q);
    TEST_ASSERT_TRUE(q == NULL, __LINE__);

    printf("\n========================================\n");
    printf("   Results: %d passed, %d failed\n", tests_passed, tests_failed);
    printf("========================================\n");

    return tests_failed > 0 ? 1 : 0;
}
