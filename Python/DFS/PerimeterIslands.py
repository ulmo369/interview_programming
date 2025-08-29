TIERRA = 1
AGUA = 0

class CityMap:
    def __init__(self, rows:int, cols:int):
        self.rows = rows
        self.cols = cols
        self.mapa = [[AGUA] * cols for _ in range(rows)]

    def addTrack(self, rows:int, cols:int):
        self.mapa[rows][cols] = TIERRA

    def trackPerimeter(self):
        perimeter = 0
        for x in range(self.rows):
            for y in range(self.cols):
                if self.mapa[x][y] == TIERRA:
                    perimeter += self.dfs(x, y, perimeter)
        return perimeter

    def dfs(self, x:int, y:int, perimeter:int):

        if x < 0 or y < 0 or x >= self.rows or y >= self.cols:
            return 1
        if self.mapa[x][y] == 2:
            return 0
        if self.mapa[x][y] != TIERRA:
            return 1
        
        self.mapa[x][y] = 2 # Mark as visited

        perimeter = 0
        perimeter += self.dfs(x + 1, y, perimeter)
        perimeter += self.dfs(x - 1, y, perimeter)
        perimeter += self.dfs(x, y + 1, perimeter)
        perimeter += self.dfs(x, y - 1, perimeter)
        return perimeter

    def printMap(self):
        print("\n".join(map(str, self.mapa)))


mapa = CityMap(5, 6)
mapa.addTrack(1, 0)
mapa.addTrack(2, 0)
mapa.addTrack(2, 1)
mapa.addTrack(2, 2)
mapa.addTrack(0, 3)
mapa.addTrack(4, 3)
mapa.addTrack(4, 2)
mapa.addTrack(4, 5)

print("\n")
print("trackPerimeter")
mapa.printMap()
print(mapa.trackPerimeter())