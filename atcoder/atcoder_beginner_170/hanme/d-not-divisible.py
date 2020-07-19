# time exceeded 

def solution():
    length = int(input())
    user_input = input()
    num_list = [int(x) for x in user_input.split()]
    result = 0
    for i in range(length):
        success = True 
        for j in range(length):
            if i == j:
                continue
            if num_list[i] >= num_list[j] and num_list[i] % num_list[j] == 0:
                success = False 
                break
        if success:
            result += 1
    
    print(result)

solution()            