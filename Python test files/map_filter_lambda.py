#lambdas are single line anonymous functions, like:
"""
op = lambda x: x*x #will do a x*x for any x variable, here 10 is passed as a argument
print(op(10))
"""

#maps = apply a particular function to all the elements of a list or array
"""
def sqr(num):
    return num*num

num = [1,2,3,4,5]
for i in map(sqr,num): #applying the function sqr on a list num
    print(i)
"""

"""
def splicer(mystr):
    if len(mystr)%2==0:
        return 'EVEN'
    else:
        return mystr[0]

names = ['Andy','maddy','cat','ohio']
print(list(map(splicer,names)))
"""

#map with lambda

"""
mynums = [1,2,3,4,5]
print(list(map(lambda num: num**2, mynums)))
"""


names = ['saptarshi','rohan','rahul']
"""
print(list(map(lambda x: x[::-1],names)))
print(list(map(lambda x:x[0],names)))
"""

#filter = returns only those values that satisfy a function

"""
def even(num):
	return num%2==0

num = [1,2,3,4,5,6]
for i in filter(even,num):
	print(i)
"""


#filter with lambda

"""
mynums = [1,2,3,4,5,6]
print(list(filter(lambda x: x%2==0, mynums)))
"""



