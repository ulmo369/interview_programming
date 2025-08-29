

print('Hello')
'''
Build a 2-dimensional representation of terrain that can represent land and water. 
isLand(x, y): returns true if a point is a land
addLand(x, y): sets a point to land
'''
'''
Extend the data-structure to add a method for getIslands() which returns the number of unique connected components of lands
. . . . X .
X . . . X . = getIslands() == 3 
X X X . . .
. . . . . X
'''
TIERRA = 1
AGUA = 0

class myMap:
    def __init__(self, rows:int, cols:int):
        self.rows = rows
        self.cols = cols
        self.matrix = [[AGUA]*cols for _ in range(rows)] # Inicializa el mapa con agua

    # Método para verificar si un punto es tierra
    def isLand(self, rows:int, cols:int):
        return self.matrix[rows][cols] == TIERRA

    # Método para agregar tierra
    def addLand(self, rows:int, cols:int):
        self.matrix[rows][cols] = TIERRA

    # Método para obtener el número de islas
    def getIsland(self): 
        cont = 0 # Contador de islas
        # Recorremos todo el mapa
        for x in range(self.rows):
            for y in range(self.cols):
                if self.matrix[x][y] == TIERRA:    # Si es tierra
                    self.dfs(x,y) # Llamamos a DFS para marcar toda la isla
                    cont += 1
        return cont
    
    def dfs(self, rows:int, cols:int):

        if rows < 0 or cols < 0 or rows >= self.rows or cols >= self.cols: # Fuera de los límites
            return
        if self.matrix[rows][cols] != TIERRA: # Si no es tierra, retornamos
            return
        
        self.matrix[rows][cols] = 2 # Mark as visited
        self.dfs(rows + 1, cols)
        self.dfs(rows - 1, cols)
        self.dfs(rows, cols + 1)
        self.dfs(rows, cols - 1)
    def printMap(self):
        print("\n".join(map(str, self.matrix)))

mapa = myMap(5, 6)
mapa.addLand(1, 0)
mapa.addLand(2, 0)
mapa.addLand(2, 1)
mapa.addLand(2, 2)
mapa.addLand(0, 3)
mapa.addLand(4, 3)
mapa.addLand(4, 2)
mapa.addLand(4, 5)
mapa.printMap()

print(mapa.getIsland())