# accepted

def solution():
    user_input = input()
    user_input = user_input.split()
    for i in range(len(user_input)):
        if user_input[i] == '0':
            print(i+1)
            return i+1



solution()
