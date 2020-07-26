# time exceeeded

def solution():
    _ = input()
    user_input = input()
    num_list = [int(x) for x in user_input.split()]

    iter = max(num_list) // min(num_list) 

    h = {}
    for num in num_list:
        h[num] = h.get(num, -1) + 1
    
    multiplier = 1
    for _ in range(iter):
        for num in h:
            if num * multiplier in h:
                h[num * multiplier] += 1
        multiplier += 1
    
    result = 0
    for _, val in h.items():
        if val == 1:
            result += 1
    print(result)

    
    

solution()            