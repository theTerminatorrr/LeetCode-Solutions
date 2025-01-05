class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])

        q = collections.deque()
        
        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 0:
                    q.append((i, j))
                else:
                    mat[i][j] = "#"

        while q:
            for _ in range(len(q)):
                row, col = q.popleft()
                for dx, dy in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
                    dr = row + dx
                    dc = col + dy
                    if 0 <= dr < rows and 0 <= dc < cols and mat[dr][dc] == "#":
                        mat[dr][dc] = mat[row][col] + 1
                        q.append((dr, dc))

        return mat
