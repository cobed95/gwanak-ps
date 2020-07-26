# accepted 

def solution():
    user_input = input()
    animals, legs = [int(x) for x in user_input.split()]

    turtles = (4*animals - legs) / 2

    condition = turtles >= 0 and turtles <= animals and turtles % 1 == 0 

    if condition:
        print("Yes")
    else:
        print("No")

solution()