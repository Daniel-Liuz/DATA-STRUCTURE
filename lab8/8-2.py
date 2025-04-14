from collections import Counter
import heapq


def topKFrequent(nums, k):
    # 使用Counter统计频率
    count = Counter(nums)

    # 使用堆来获取前k个高频元素
    heap = []
    for num, freq in count.items():
        heapq.heappush(heap, (-freq, num))  # 使用负频率来创建最大堆

    # 获取前k个元素
    result = []
    for _ in range(k):
        result.append(heapq.heappop(heap)[1])

    return sorted(result)  # 按题目要求从小到大排序


# 读取输入
n = int(input())
nums = list(map(int, input().split()))
k = int(input())

# 输出结果
result = topKFrequent(nums, k)
print(' '.join(map(str, result)))
