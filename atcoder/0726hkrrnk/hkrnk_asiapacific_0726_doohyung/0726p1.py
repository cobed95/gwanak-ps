def minimumMoves(s, d):
    n = len(s)
    conseczeroocc = 0
    conseczerolist = []
    for i in range(n-d+1):
        while s[i]

    # find the occasions of consecutive zeros with length >=d, and identify the length of each occasions
    # mu = Number of consecutive invalid d-length strings = number of consecutive zeros-d+1
    # for each occasion of consecutive zeros, the required number of "moves " is len(conseczero)//d

    return(moves)


