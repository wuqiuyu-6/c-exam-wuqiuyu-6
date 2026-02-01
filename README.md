# C 语言作业模板

基于 CMake 的 C 语言项目模板，适用于课程作业和小型项目。

## 项目结构

```text
├── CMakeLists.txt    # CMake 构建配置
├── README.md         # 项目说明
├── .gitignore        # Git 忽略配置
├── bin/              # 编译输出目录
├── include/          # 头文件 (*.h)
├── src/              # 源文件 (*.c)
└── tests/            # 测试文件 (可选)
```

## 构建和运行

```bash
cmake -B build
cmake --build build
```

## 测试

```bash
ctest --test-dir build
```

## 目录规范

| 目录       | 用途                    |
| ---------- | ----------------------- |
| `src/`     | 源文件，`main.c` 为入口 |
| `include/` | 头文件                  |
| `bin/`     | 编译产物                |

## 编译选项

```bash
# Debug 版本
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Release 版本
cmake -DCMAKE_BUILD_TYPE=Release ..
```

## 注意事项

1. 在 `src/` 下编写代码，源文件自动被包含
2. 头文件放入 `include/` 目录
3. 清理构建：`cmake --build . --target clean`
4. 不要修改 `test/` 和 `scripts/test/` 下的测试文件

## 队列作业要求

### 数据结构

使用**链表**实现链式队列，包含以下结构：

- `QueueNode` - 队列节点，包含数据域和指针域
- `Queue` - 队列主结构，包含 front、rear、size、capacity

### 核心操作

| 函数                       | 功能     | 时间复杂度 |
| -------------------------- | -------- | ---------- |
| `queue_create(capacity)`   | 创建队列 | O(1)       |
| `queue_destroy(&q)`        | 销毁队列 | O(n)       |
| `queue_enqueue(q, value)`  | 入队     | O(1)       |
| `queue_dequeue(q, &value)` | 出队     | O(1)       |
| `queue_front(q)`           | 查看队首 | O(1)       |
| `queue_back(q)`            | 查看队尾 | O(1)       |
| `queue_is_empty(q)`        | 判空     | O(1)       |
| `queue_is_full(q)`         | 判满     | O(1)       |
| `queue_size(q)`            | 获取大小 | O(1)       |
| `queue_clear(q)`           | 清空队列 | O(n)       |

### 特性要求

1. **FIFO 特性**：先进先出，入队顺序与出队顺序一致
2. **容量限制**：支持设置最大容量（capacity=0 表示无限制）
3. **内存安全**：正确处理 NULL 指针，销毁时释放所有节点
4. **边界处理**：空队出队/获取元素时返回 false/0

### 运行测试

```bash
# 构建并运行测试
cmake -B build
cmake --build build
./build/test/test_queue
```

---

## 许可证

[Apache-2.0](LICENSE)
