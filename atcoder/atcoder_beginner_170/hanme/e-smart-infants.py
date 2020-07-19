# time exceeded 

def solution():
    user_input = input()
    N, Q = [int(x) for x in user_input.split()]

    kid_info = {}
    kindergarten_info = {}

    for kid in range(1, N+1):
        user_input = input()
        rating, kindergarten = [int(x) for x in user_input.split()]

        kid_info[kid] = kindergarten

        if kindergarten not in kindergarten_info:
            kindergarten_info[kindergarten] = {kid: rating}
        else:
            kindergarten_info[kindergarten][kid] = rating
    
    results = []
    for kid in range(1, Q+1):
        user_input = input()
        kid, new_kindergarten = [int(x) for x in user_input.split()] 

        prev_kindergarten = kid_info[kid]
        rating = kindergarten_info[prev_kindergarten][kid]
        del kindergarten_info[prev_kindergarten][kid]
    
        kid_info[kid] = new_kindergarten
    
        if new_kindergarten not in kindergarten_info:
            kindergarten_info[new_kindergarten] = {kid: rating}
        else:
            kindergarten_info[new_kindergarten][kid] = rating
        
        max_ratings = []
        for kindergarten, kid_dict in kindergarten_info.items():
            if len(kid_dict.values()) == 0:
                continue
            maximum = 0
            for kid, ratings in kid_dict.items():
                if ratings > maximum:
                    maximum = ratings
            max_ratings.append(maximum)
        results.append(min(max_ratings))

    for result in results:
        print(result)


solution()


    
        
        
