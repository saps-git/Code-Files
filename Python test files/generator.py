#WHY ARE GENERATORS USED?
"""
A normal function to return a sequence will create the entire 
sequence in memory before returning the result. This is an overkill, 
if the number of items in the sequence is very large.

Generator implementation of such sequences is memory friendly and is 
preferred since it only produces one item at a time.
"""

"""
The difference is that while a return statement terminates a function 
entirely, yield statement pauses the function saving all its states 
and later continues from there on successive calls
"""

#Generator using simple function
"""
def square_numbers(nums):
    for i in nums:
        yield (i*i)

my_nums = square_numbers([1,2,3,4,5])
"""

#print(my_nums) #his will give a object

#Printing with next()
#next() is used as generators yeild one element at a time, so next() iterates over them one by one
"""
print(next(my_nums)) #this will return the first element
print(next(my_nums)) #this will return the second element
print(next(my_nums)) #this will return the third element
print(next(my_nums)) #this will return the fourth element
print(next(my_nums)) #this will return the fifth element
print(next(my_nums)) #this will give error, as there is no more element
"""
#Printing with loop
"""
for num in my_nums:
    print num
"""

#Generator using comprehension
my_nums = (x*x for x in [1,2,3,4,5])
for num in my_nums:
    print(num)

#Converting to a list, but it will lose all its advantages
"""
print (list(my_nums)) # [1, 4, 9, 16, 25] #it needs to be converted into a list
"""