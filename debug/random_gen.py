from random import randint
import random
import string

def rd_string(n:int)->str:
    return ''.join(random.choices(string.ascii_lowercase,k=n))

def rd_array(l:int, r:int, n:int)->list[int]:
    return [randint(l, r) for _ in range(n)]

def rd_perm(n:int)->list[int]:
    return random.sample(range(1,n+1),n)

def rd_chars(n:int,chars:str='()')->str:
    return ''.join(random.choices(chars, k=n))

def rd_grid(h:int, w:int, chars:str='.#', weights:list[float]|None=None,) -> list[str]:
    return [''.join(random.choices(chars,weights=weights,k=w))for _ in range(h)]
# for row in grid:
#     print(row)

def place_sg(grid: list[str]) -> list[str]:
    h = len(grid)
    w = len(grid[0])

    s, g = random.sample(range(h * w), 2)

    result = [list(row) for row in grid]

    result[s // w][s % w] = 'S'
    result[g // w][g % w] = 'G'

    return [''.join(row) for row in result]

def rd_connected_graph(n: int, m: int) -> list[tuple[int, int]]:
    if m < n - 1:
        raise ValueError(f"connected graph requires m >= n - 1, but got n={n}, m={m}")
    if m > n * (n - 1) // 2:
        raise ValueError(
            f"simple graph requires m <= n(n-1)/2, but got n={n}, m={m}"
        )
    edges = set()
    for v in range(2, n + 1):
        u = randint(1, v - 1)
        edges.add((u, v))

    while len(edges) < m:
        u, v = random.sample(range(1, n + 1), 2)
        if u > v:
            u, v = v, u
        edges.add((u, v))

    edges = list(edges)
    random.shuffle(edges)

    return edges

# nをk分割
def rd_part(n: int, k: int) -> list[int]:
    cuts = sorted(random.sample(range(n + k - 1), k - 1))

    result = [cuts[0]]

    for i in range(1, k - 1):
        result.append(cuts[i] - cuts[i - 1] - 1)

    result.append(n + k - 2 - cuts[-1])

    return result
