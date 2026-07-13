values = list(map(int, input().split()))

max_val = max(values)
filtered_values = [val for val in values if val != max_val]
if not filtered_values:
    print(-1)
else:
    print(max(filtered_values))