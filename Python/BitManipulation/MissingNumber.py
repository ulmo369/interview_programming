nums = [3, 0, 1]

res = len(nums)

for i in range(len(nums)):
    res = res ^ i ^ nums[i]
    
res = 1^2
        
print(res)