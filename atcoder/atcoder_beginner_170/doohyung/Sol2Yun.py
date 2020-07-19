
# coding: utf-8

# In[ ]:


x = int(input())
y = int(input())


# In[ ]:


if y%2==0:
    t = [0]*(2*x+1)
    for i in range(2*x+1):
        if 2*x-i == y//2:
            t[i] = 1
        else:
            t[i] = 0
    if sum(t)==0:
        print('No')
    else:
        print('Yes')
            
else:
    print('No')

