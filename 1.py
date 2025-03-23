s=input().strip()
sum_beauty=0
n=len(s)
for i in range(n):
    freq=[0]*26#初始化频率数组
    for j in range(i,n):
        c=ord(s[j])-ord('a')#将字符串映射到频率数组
        freq[c]+=1
        current_max=max(freq)
        current_min=float('inf')#初始化为无穷大
        for k in range (n):
            if freq[k]>0:#只考虑不为0的情况
                current_min=min(current_min,freq[k])
        sum_beauty+=(current_max-current_min)
print (sum_beauty)