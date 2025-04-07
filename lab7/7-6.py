class Node:
    def __init__(self, val=0, min_val=0, next=None):
        self.val = val
        self.min_val = min_val  # 存储当前节点及以下的最小值
        self.next = next


class MinStack:
    def __init__(self):
        self.head = None

    def push(self, val):
        if not self.head:
            self.head = Node(val, val)
        else:
            new_node = Node(val, min(val, self.head.min_val))
            new_node.next = self.head
            self.head = new_node
        return None

    def pop(self):
        if not self.head:
            return None
        self.head = self.head.next
        return None

    def top(self):
        if not self.head:
            return None
        return self.head.val

    def getMin(self):
        if not self.head:
            return None
        return self.head.min_val

    def isEmpty(self):
        return self.head is None


# 主程序
def main():
    # 读取输入
    operations = input().strip().split(',')
    params = input().strip().split(',')

    # 初始化结果列表
    result = []
    min_stack = None

    # 依次处理每个操作
    for op, param in zip(operations, params):
        if op == "MinStack":
            min_stack = MinStack()
            result.append("null")
        elif op == "push":
            result.append("null")
            min_stack.push(int(param))
        elif op == "pop":
            value = min_stack.pop()
            result.append("null")  # pop 不需要返回值，始终输出 null
        elif op == "top":
            value = min_stack.top()
            result.append(str(value) if value is not None else "null")
        elif op == "getMin":
            value = min_stack.getMin()
            result.append(str(value) if value is not None else "null")
        elif op == "isEmpty":
            result.append("true" if min_stack.isEmpty() else "false")

    # 输出结果
    print(','.join(result))


if __name__ == "__main__":
    main()