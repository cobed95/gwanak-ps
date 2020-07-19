# accepted 

def solution():
    input1 = input()
    input2 = input()
    target, _ = [int(x) for x in input1.split()]
    num_list = set()
    for n in input2.split():
        num_list.add(int(n))
    diff = 0
    while True:
        candidate1 = target - diff
        candidate2 = target + diff
        if candidate1 not in num_list:
            print(candidate1)
            return
        if candidate2 not in num_list:
            print(candidate2)
            return
        diff += 1
    
solution()



        
