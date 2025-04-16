s=input().strip()
n=len(s)
sum_beauty=0
for i in range (n):
    freq=[0]*26
    for j in range(i,n):
        c=ord(s[j])-ord('a')
        freq[c]+=1
        current_max=max(freq)
        current_min=float('inf')
        for k in range(26):
            if freq[k]>0:
                current_min=min(current_min,freq[k])
        sum_beauty+=(current_max-current_min)
print (sum_beauty)