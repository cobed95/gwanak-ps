# accepted 

def solution():
    user_input = input()
    animals, legs = [int(x) for x in user_input.split()]

    if 4*animals < legs:
        print("No")
        return
    
    if 2*animals > legs:
        print("No")
        return

    turtles = animals 
    cranes = 0 

    while cranes <= animals:
        if 4*turtles + 2*cranes == legs:
            print("Yes")
            return
        
        turtles -= 1
        cranes += 1

    print("No")
        
        
        
solution()