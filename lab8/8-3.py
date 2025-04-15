from collections import Counter, defaultdict


def isPossible(nums):
    # 统计每个数字的频率
    count = Counter(nums)
    # 记录以某个数字结尾的序列的数量
    end = defaultdict(int)

    # 遍历数组中的每个数字
    for num in nums:
        # 如果当前数字已经用完，继续下一个
        if count[num] == 0:
            continue

        # 优先判断是否可以加入已有序列
        if end[num - 1] > 0:
            # 将当前数字加入到以 num-1 结尾的序列中
            end[num - 1] -= 1
            end[num] += 1
            count[num] -= 1
        else:
            # 尝试新建一个长度为3的序列
            if count[num + 1] > 0 and count[num + 2] > 0:
                count[num] -= 1
                count[num + 1] -= 1
                count[num + 2] -= 1
                end[num + 2] += 1
            else:
                # 无法形成长度为3的序列
                return False

    return True


# 读取输入
n = int(input())
nums = list(map(int, input().split()))

# 输出结果
result = isPossible(nums)
print(str(result).lower())  # 转换为小写的 'true' 或 'false'
