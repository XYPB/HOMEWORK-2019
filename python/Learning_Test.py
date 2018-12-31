
# coding: utf-8

# In[6]:


a = [1, 2, 3, 4, 5]
a_iter = iter(a)
for i in range(5):
    print(next(a_iter))


# In[7]:


try:
    print(next(a_iter))
except StopIteration:
    print('Iterator out of range')


# In[17]:


def xjbfunc(a):
    while 1 == 1:
        if (a > 10):
            return 0
        a += 1
        print(a)

print(xjbfunc(0))


# In[23]:


print((lambda x, y : x + y)(2, 3))


# In[26]:


x = 'Suprise MF!'
print([i for i in range(len(x)) if x[i] == 's' or x[i] == 'S'])

