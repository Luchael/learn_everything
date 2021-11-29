exp_table={
    0:3,
    2:4
}
def currentExp(level: int):
    global exp_table
    try:
        exp = exp_table[level]
    except KeyError:
        exp = -1
    finally:
        return exp
print(currentExp(1))
print(currentExp(2))
