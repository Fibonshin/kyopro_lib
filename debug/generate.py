from random_gen import(
        rd_string,
        rd_array,
        rd_grid,
        place_sg,
        rd_chars,
        rd_connected_graph,
        rd_perm,
        rd_part,
        randint,
)

import random

n,k=5,3
print(n,k)
for i in range(n):
    print(rd_chars(randint(1,4),"ab"))
