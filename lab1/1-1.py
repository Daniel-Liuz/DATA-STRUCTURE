# 读取输入并去除可能存在的首尾空白字符
s = input().strip()

# 初始化美丽值之和
sum_beauty = 0

# 获取字符串长度
n = len(s)

# 外层循环：遍历所有可能的子字符串起始位置
for i in range(n):
    # 创建一个长度为26的数组，用于统计26个小写字母出现的次数
    # 索引0代表'a'，1代表'b'，以此类推
    freq = [0] * 26

    # 内层循环：遍历从i开始到字符串末尾的所有可能结束位置
    for j in range(i, n):#在python中，是以str的形式存储，所以不能直接相减，而是要调用ord()函数
        # 将字符转换为0-25的索引
        # ord(s[j]) 得到字符的ASCII值
        # ord('a') 得到字母'a'的ASCII值
        # 两者相减得到字符在数组中的位置
        c = ord(s[j]) - ord('a')

        # 将当前字符的出现次数加1
        freq[c] += 1

        # 找出当前出现次数最多的字符的次数
        current_max = max(freq)

        # 初始化最小值为无穷大
        current_min = float('inf')

        # 遍历频率数组，找出所有出现过的字符中，出现次数最少的
        for k in range(26):
            # 只考虑出现过的字符（频率大于0）
            if freq[k] > 0:
                current_min = min(current_min, freq[k])

        # 计算美丽值（最大频率 - 最小频率）并加到总和中
        sum_beauty += (current_max - current_min)

# 输出最终结果
print(sum_beauty)
