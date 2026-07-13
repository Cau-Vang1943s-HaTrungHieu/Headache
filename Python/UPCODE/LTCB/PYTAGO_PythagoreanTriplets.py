def find_pythagorean_triplets(limit):
    triplets = []
    for a in range(1, limit):
        for b in range(a, limit):
            c = (a**2 + b**2)**0.5
            if c.is_integer() and c <= limit:
                triplets.append((a, b, int(c)))
    return triplets

try:
    limit = int(input())
    if (limit < 1):
        print(-1)
    else:
        pythagorean_triplets = find_pythagorean_triplets(limit)
        if pythagorean_triplets:
            for a, b, c in pythagorean_triplets:
                print(f"{a} {b} {c}")
except: 
    print(-1)


"""
n = int(input())
found = False
for a in range(1, n + 1):
    for b in range(a + 1, n + 1):
        c = (a**2 + b **2)**0.5
        if c == int(c) and c <= n:
            print(a,b,int(c))
            found = True
if not found:
    print(-1)
"""