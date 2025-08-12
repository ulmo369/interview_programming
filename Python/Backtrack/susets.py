def subsets(nums):
    solucion = []
    resultado = []

    def bt(visited):

        if visited >= len(nums):
            resultado.append(solucion.copy())
            return

        solucion.append(nums[visited])
        bt(visited+1)

        solucion.pop()
        bt(visited+1)
    
    bt(0)
    return resultado

print(subsets([1,2,3]))