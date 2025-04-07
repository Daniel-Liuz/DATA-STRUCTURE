class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def create_cycle_linked_list(arr, pos):
    # 处理空输入
    if arr == 'n':
        return None

    # 将输入字符串按逗号分割并转换为整数列表
    nums = [int(x) for x in arr.split(',')]
    if not nums:
        return None

    # 创建链表
    head = ListNode(nums[0])
    current = head
    nodes = [head]  # 保存所有节点用于创建环

    # 创建除第一个节点外的其余节点
    for val in nums[1:]:
        current.next = ListNode(val)
        current = current.next
        nodes.append(current)

    # 如果 pos >= 0，创建环
    if pos >= 0 and pos < len(nodes):
        current.next = nodes[pos]

    return head


def get_linked_list_values(head):
    # 如果链表为空，返回 'n'
    if not head:
        return 'n'

    result = []
    current = head
    seen = set()  # 用于检测环
    count = 0

    # 遍历链表
    while current and count < 10:
        # 如果发现环，记录当前节点的值
        if id(current) in seen:
            # 如果有环，继续输出直到 10 个元素
            cycle_start = current
            while count < 10:
                result.append(str(current.val))
                current = current.next
                count += 1
            break

        # 记录当前节点 ID 和值
        seen.add(id(current))
        result.append(str(current.val))
        current = current.next
        count += 1

    # 如果没有环且长度不足 10，直接返回所有元素
    return ','.join(result)


# 主程序
def main():
    # 读取输入
    arr = input().strip()
    pos = int(input().strip())

    # 创建环形链表
    head = create_cycle_linked_list(arr, pos)

    # 输出结果
    print(get_linked_list_values(head))


if __name__ == "__main__":
    main()