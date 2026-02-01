cmake_minimum_required(VERSION 3.14)

# 项目信息
project(c-assignment-template
    VERSION 1.0.0
    DESCRIPTION "C语言作业通用基础模板"
    LANGUAGES C
)

# C标准配置
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# 编译选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=return-type -Werror")
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -DDEBUG")

# 输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 源文件
file(GLOB SOURCES "src/*.c")
list(SORT SOURCES)

# 可执行文件
add_executable(main ${SOURCES})
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

# 安装目标（可选）
install(TARGETS main DESTINATION bin)

# ==========================================
# 单元测试支持 (CTest)
# ==========================================
enable_testing()

# 单独测试: 创建和销毁
add_executable(test_01_create_destroy test/test_01_create_destroy.c src/queue.c)
target_include_directories(test_01_create_destroy PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME test_01_create_destroy COMMAND test_01_create_destroy)

# 单独测试: 空队列判断
add_executable(test_02_is_empty test/test_02_is_empty.c src/queue.c)
target_include_directories(test_02_is_empty PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME test_02_is_empty COMMAND test_02_is_empty)

# 单独测试: 入队和出队
add_executable(test_03_enqueue_dequeue test/test_03_enqueue_dequeue.c src/queue.c)
target_include_directories(test_03_enqueue_dequeue PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME test_03_enqueue_dequeue COMMAND test_03_enqueue_dequeue)

# 单独测试: 队首元素
add_executable(test_04_front test/test_04_front.c src/queue.c)
target_include_directories(test_04_front PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME test_04_front COMMAND test_04_front)

# 单独测试: 队尾元素
add_executable(test_05_back test/test_05_back.c src/queue.c)
target_include_directories(test_05_back PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME test_05_back COMMAND test_05_back)

# 单独测试: 队列大小
add_executable(test_06_size test/test_06_size.c src/queue.c)
target_include_directories(test_06_size PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME test_06_size COMMAND test_06_size)

# 单独测试: 清空队列
add_executable(test_07_clear test/test_07_clear.c src/queue.c)
target_include_directories(test_07_clear PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME test_07_clear COMMAND test_07_clear)

# 单独测试: 出队获取值
add_executable(test_08_dequeue_value test/test_08_dequeue_value.c src/queue.c)
target_include_directories(test_08_dequeue_value PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME test_08_dequeue_value COMMAND test_08_dequeue_value)

# 单独测试: 无容量限制
add_executable(test_09_unlimited_capacity test/test_09_unlimited_capacity.c src/queue.c)
target_include_directories(test_09_unlimited_capacity PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME test_09_unlimited_capacity COMMAND test_09_unlimited_capacity)

# 单独测试: FIFO特性
add_executable(test_10_fifo_order test/test_10_fifo_order.c src/queue.c)
target_include_directories(test_10_fifo_order PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME test_10_fifo_order COMMAND test_10_fifo_order)
