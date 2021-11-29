def xor(a, b):
    if (a or b) and not(a and b):
        return True
    return False

print(xor(1, 2), xor(1, 0), xor(0, 1), xor(0, 0), sep='\n')