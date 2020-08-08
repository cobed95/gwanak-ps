def last(ls):
    if len(ls) == 0:
        raise ValueError

    head, *tail = ls
    if len(tail) == 0:
        return head
    else:
        return last(tail)

