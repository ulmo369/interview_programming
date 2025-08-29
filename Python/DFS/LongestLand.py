TIERRA = 1
AGUA = 0

class CityMap:
    def __init__(self, rows:int, cols:int):
        self.rows = rows
        self.cols = cols
        self.mapa = [[AGUA] * cols for _ in range(rows)]

    def addTrack(self, rows:int, cols:int):
        self.mapa[rows][cols] = TIERRA

    def longestRoute(self):
        max_route = 0
        for x in range(self.rows):
            for y in range(self.cols):
                if self.mapa[x][y] == TIERRA:
                    max_route = max(max_route, self.dfs_for_longestRoute(x, y))
        return max_route

    def dfs_for_longestRoute(self, x:int, y:int):
        if x < 0 or y < 0 or x >= self.rows or y >= self.cols:
            return 0
        if self.mapa[x][y] != 1:
            return 0

        self.mapa[x][y] = 2 # Mark as visited
        count = 1
        count += self.dfs_for_longestRoute(x + 1, y)
        count += self.dfs_for_longestRoute(x - 1, y)
        count += self.dfs_for_longestRoute(x, y + 1)
        count += self.dfs_for_longestRoute(x, y - 1)
        return count

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
print("longestRoute")
mapa.printMap()
print(mapa.longestRoute())