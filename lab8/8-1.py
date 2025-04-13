class MyHashSet:
    def __init__(self):
        self.size = 10**6 + 1  # 由于 key 的范围是 0 <= key <= 10^6, 可以用一个大数组来存储哈希集合
        self.hash_set = [False] * self.size  # 初始化哈希集合为全 False

    def add(self, key: int):
        self.hash_set[key] = True  # 将对应位置标记为 True，表示该 key 存在

    def remove(self, key: int):
        self.hash_set[key] = False  # 将对应位置标记为 False，表示该 key 不存在

    def contains(self, key: int) -> bool:
        return self.hash_set[key]  # 如果为 True，表示 key 存在


# 读取输入
n, m, k = map(int, input().split())  # 读取 n, m, k
add_values = list(map(int, input().split()))  # 读取插入的 n 个值
remove_values = list(map(int, input().split()))  # 读取删除的 m 个值
query_values = list(map(int, input().split()))  # 读取查询的 k 个值

# 初始化哈希集合
my_set = MyHashSet()

# 执行插入操作
for value in add_values:
    my_set.add(value)

# 执行删除操作
for value in remove_values:
    my_set.remove(value)

# 执行查询操作
result = []
for value in query_values:
    if my_set.contains(value):
        result.append(1)
    else:
        result.append(0)

# 输出结果
print(' '.join(map(str, result)))
