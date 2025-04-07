class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def create_linked_list(arr):
    # 如果输入是'n'，返回空链表
    if arr == 'n':
        return None
    # 将输入字符串按逗号分割并转换为整数列表
    nums = [int(x) for x in arr.split(',')]
    if not nums:
        return None
    # 创建链表
    head = ListNode(nums[0])
    current = head
    for val in nums[1:]:
        current.next = ListNode(val)
        current = current.next
    return head


def merge_two_lists(l1, l2):
    # 创建哑节点作为结果链表的开头
    dummy = ListNode(0)
    current = dummy

    # 当两个链表都有节点时
    while l1 and l2:
        if l1.val <= l2.val:
            current.next = l1
            l1 = l1.next
        else:
            current.next = l2
            l2 = l2.next
        current = current.next

    # 处理剩余的节点
    if l1:
        current.next = l1
    if l2:
        current.next = l2

    return dummy.next


def print_linked_list(head):
    if head is None:
        return ""
    result = []
    current = head
    while current:
        result.append(str(current.val))
        current = current.next
    return ','.join(result)


# 主程序
def main():
    # 读取输入
    nums1 = input().strip()
    nums2 = input().strip()

    # 如果两个输入都是'n'，直接返回'n'
    if nums1 == 'n' and nums2 == 'n':
        print('n')
        return

    # 创建两个链表
    l1 = create_linked_list(nums1)
    l2 = create_linked_list(nums2)

    # 合并链表
    merged = merge_two_lists(l1, l2)

    # 输出结果
    if merged:
        print(print_linked_list(merged))
    else:
        print("")


if __name__ == "__main__":
    main()