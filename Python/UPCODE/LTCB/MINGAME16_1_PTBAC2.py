import math
a, b, c = map(int, input().split())

if a == 0:
    if b == 0:
        if c == 0: print(-1)
        else: print(0)
    else:
        print(1) 
        x = -c / b
        if x == 0: x = 0.0
        print(f"{x:.10f}")
else:
    delta = b*b - 4*a*c
    if delta < 0: print(0)
    elif delta == 0:
        print(1) 
        print(f"{-b/(2*a):.10f}")
    else:
        sqrt_delta = math.sqrt(delta)
        x1 = (-b - sqrt_delta) / (2 * a)
        x2 = (-b + sqrt_delta) / (2 * a)
        print(2)
        print(f"{min(x1, x2):.10f}")
        print(f"{max(x1, x2):.10f}")
