class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        ans = []

        def bt(visited, count, solution):

            if count == target:
                ans.append(solution.copy())
                return
            if visited >= len(candidates) or count > target:
                return

            solution.append(candidates[visited])
            bt(visited, count+candidates[visited], solution)

            solution.pop()
            bt(visited+1, count, solution)
        
        bt(0, 0, [])
        return ans
