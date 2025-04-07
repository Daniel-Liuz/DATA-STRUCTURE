class MyQueue:
    def __init__(self):
        self.queue = []

    def push(self, x):
        self.queue.append(x)
        return None

    def pop(self):
        if self.queue:
            return self.queue.pop(0)
        return None

    def peek(self):
        if self.queue:
            return self.queue[0]
        return None

    def empty(self):
        return len(self.queue) == 0


# 主程序
def main():
    # 读取输入
    operations = input().strip().split(',')
    params = input().strip().split(',')

    # 初始化结果列表
    result = []
    myQueue = None

    # 依次处理每个操作
    for op, param in zip(operations, params):
        if op == "MyQueue":
            myQueue = MyQueue()
            result.append("null")
        elif op == "push":
            value = myQueue.push(int(param))
            result.append("null")  # push 总是返回 null
        elif op == "pop":
            value = myQueue.pop()
            result.append(str(value) if value is not None else "null")
        elif op == "peek":
            value = myQueue.peek()
            result.append(str(value) if value is not None else "null")
        elif op == "empty":
            result.append("true" if myQueue.empty() else "false")

    # 输出结果
    print(','.join(result))


if __name__ == "__main__":
    main()