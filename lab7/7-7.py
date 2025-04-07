def trap(height):
    if not height or len(height) < 3:
        return 0

    left, right = 0, len(height) - 1
    left_max, right_max = 0, 0
    water = 0

    while left < right:
        # 更新左右最大高度
        left_max = max(left_max, height[left])
        right_max = max(right_max, height[right])

        # 如果左边最大高度小于右边最大高度，处理左边
        if left_max < right_max:
            water += left_max - height[left]
            left += 1
        # 否则处理右边
        else:
            water += right_max - height[right]
            right -= 1

    return water


# 主程序
def main():
    # 读取输入
    arr = input().strip()
    if not arr:
        print(0)
        return

    # 将输入字符串转换为整数数组
    height = [int(x) for x in arr.split(',')]

    # 计算接雨水量并输出
    print(trap(height))


if __name__ == "__main__":
    main()