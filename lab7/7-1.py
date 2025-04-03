def nextGreaterElement(nums1, nums2):
    next_greater = {}#这里是以字典的方式存储的
    stack = []
    for num in nums2:
        while stack and stack[-1] < num:
            next_greater[stack.pop()] = num
        stack.append(num)
    while stack:
        next_greater[stack.pop()] = -1

    ans = [next_greater[num] for num in nums1]
    return ans

nums1 = list(map(int, input().split(',')))
nums2 = list(map(int, input().split(',')))
result = nextGreaterElement(nums1, nums2)

print(','.join(map(str, result)))