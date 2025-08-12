def subset2_0(nums, k):

    solutions = []
    res = []

    def bt(visited):


        if len(solutions) == k:
            res.append(solutions.copy())
            return
        
        if visited >= len(nums):
            return
        

        solutions.append(nums[visited])
        bt(visited+1)

        solutions.pop()
        bt(visited + 1)

    bt(0)
    print(res)



subset2_0([4, 5, 6, 7], 3)