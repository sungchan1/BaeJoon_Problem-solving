from sys import stdin

class SegTree:
    def __init__(self, data):
        n = len(data)
        self.tree = [float("inf")] * (2 * n)

        # 리프 노드에 채움
        for i in range(n):
            self.tree[n + i] = data[i]

        # 바텀업으로 채움
        for i in range(n - 1, 0, -1):
            self.tree[i] = min(self.tree[2 * i], self.tree[2 * i + 1])

    def query(self, start, end):
        n = len(self.tree) // 2
        start += n
        end += n
        result = float("inf")

        while start < end:
            if start % 2 == 1:
                result = min(result, self.tree[start])
                start += 1
            if end % 2 == 1:
                end -= 1
                result = min(result, self.tree[end])
            start //= 2
            end //= 2


        return result


n, m = map(int, stdin.readline().split())
data = [ int(stdin.readline()) for _ in range(n)]
seg_tree = SegTree(data)

for _ in range(m):
    start, end = map(int, stdin.readline().split())
    print(seg_tree.query(start-1, end))
