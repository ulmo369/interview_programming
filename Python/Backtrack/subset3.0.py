from typing import List

def subsets(nums: List[int]) -> List[List[int]]:
    res = []
    subset = []
    n = len(nums)

    def bt(i: int):
        if i == n:
            res.append(subset.copy())   # power set normal
            return

        # --- INCLUIR nums[i] ---
        subset.append(nums[i])

        # Extra: si es el PRIMER elemento del subset, generamos también [x,x]
        if len(subset) == 1:
            subset.append(nums[i])      # duplicamos para crear [x,x]
            res.append(subset.copy())   # añadimos la pareja con repetición
            subset.pop()                # deshacemos la duplicación y seguimos

        bt(i + 1)                       # continuamos DFS normal
        subset.pop()                    # backtrack

        # --- NO INCLUIR nums[i] ---
        bt(i + 1)

    bt(0)
    return res

# Ejemplo
print(subsets([1,2,3]))