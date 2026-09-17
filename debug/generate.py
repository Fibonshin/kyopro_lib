from random_gen import(
        rd_string,
        rd_array,
        rd_grid,
        place_sg,
        rd_bracket,
        rd_connected_graph,
        rd_perm,
        randint,
)

n=4
g=rd_connected_graph(n,4)
print(n)
for u,v in g:
    print(u,v)
