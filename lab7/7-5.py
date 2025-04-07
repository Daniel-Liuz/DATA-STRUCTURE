class Node:
    def __init__(self, val=0):
        self.val = val
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, val):
        new_node = Node(val)
        if not self.head:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node

    def remove_nodes(self):
        if not self.head or not self.head.next:
            return

        current = self.head
        while current and current.next:
            # 检查右侧是否有更大的值
            temp = current.next
            has_larger = False
            while temp:
                if temp.val > current.val:
                    has_larger = True
                    break
                temp = temp.next

            # 如果右侧有更大的值，移除当前节点
            if has_larger:
                # 如果是头节点
                if current == self.head:
                    self.head = current.next
                    self.head.prev = None
                # 如果不是头节点
                else:
                    current.prev.next = current.next
                    current.next.prev = current.prev
                current = current.next
            else:
                current = current.next

    def print_reverse(self):
        if not self.tail:
            return ""
        result = []
        current = self.tail
        while current:
            result.append(str(current.val))
            current = current.prev
        return ','.join(result)


# 主程序
def main():
    # 读取输入
    arr = input().strip()
    if not arr:
        print("")
        return

    # 创建双向链表并插入元素
    dll = DoublyLinkedList()
    nums = [int(x) for x in arr.split(',')]
    for num in nums:
        dll.insert(num)

    # 移除右侧有更大值的节点
    dll.remove_nodes()

    # 从尾节点输出
    print(dll.print_reverse())


if __name__ == "__main__":
    main()