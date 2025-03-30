import random


def quick_select(nums, left, right, k):
    if left == right:
        return nums[left]

    pivot_index = random.randint(left, right)
    pivot_index = partition(nums, left, right, pivot_index)

    # 计算pivot位置在排序后数组中的索引（从0开始）
    target_index = len(nums) - k  # 第k大元素在排序数组中的位置（从小到大排序）

    if pivot_index == target_index:
        return nums[pivot_index]
    elif pivot_index > target_index:  # 目标在左侧
        return quick_select(nums, left, pivot_index - 1, k)
    else:  # 目标在右侧
        return quick_select(nums, pivot_index + 1, right, k)


def partition(nums, left, right, pivot_index):
    pivot_value = nums[pivot_index]
    # 将pivot元素移到右侧
    nums[pivot_index], nums[right] = nums[right], nums[pivot_index]
    store_index = left

    # 这里使用 < 而不是 >，因为我们将按照升序排序来考虑索引
    for i in range(left, right):
        if nums[i] < pivot_value:
            nums[store_index], nums[i] = nums[i], nums[store_index]
            store_index += 1

    # 把pivot元素放回正确的位置
    nums[right], nums[store_index] = nums[store_index], nums[right]
    return store_index


def find_kth_largest(nums, k):
    return quick_select(nums, 0, len(nums) - 1, k)


# 输入
n = int(input())  # 数组的长度
nums = list(map(int, input().split()))  # 数组
k = int(input())  # k值

# 输出第k个最大的元素
print(find_kth_largest(nums, k))
