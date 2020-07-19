
# coding: utf-8

# In[1]:


x = [0]*5


# In[ ]:


for i in range(5):
    x[i] = int(input())


# In[ ]:


for i in range(len(x)):
    if x[i]==0:
        print(i+1)
    else:
        x[i]=x[i]

