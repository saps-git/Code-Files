#LIST(Mutable, Hetrogenous)
"""
list_1 = ['History', 'Math', 'Physics', 'CompSci']

#some list functions
print(len(list_1))

print(list_1[0])
print(list_1[-1]) # -1 starting from the last
print(list_1[0:2]) #last index (here 2) will not ne included
print(list_1[:2]) # same as above
print(list_1[2:]) # 2(including) to end

list_1.append('Biolozzy') #adding to last
list_1.insert(0,'Art') #inserting at a pos
print(list_1)

list_2 = ['Art','Education']
list_1.extend(list_2) #adding a new list at the end
print(list_1)

list_1.remove('History')
popped= list_1.pop() #removing from the last
print(list_1)
print(popped)

list_1.reverse()
print(list_1)
list_1.sort()
print(list_1) #sorting alphabatecillay

list_1.sort(reverse=True) #soritng in reverse
print(list_1)

sort = sorted(list_1) #sorting the list without actually altering the original
print(sort)
print(list_1)

print(min(list_1))
print(max(list_1))

nums = [1,2,3,4,5]
print(sum(nums))

print(list_1.index('Math'))
print('Math' in list_1) # to see if it is in the list

for i,c in enumerate(list_1, start=1): #prints the index as well as the element, can also set the starting value
    print(i,c)

#converting list into string  
course = ' - '.join(list_1)
print(course)
course2 = ' , '.join(list_1)
print(course2)

#converting string to list
new_lsit= course.split(' - ') #spliting the above string on every ' - ' (hyphens), and converting them to a list
print(new_lsit)
"""
"""
#Problem with list (mutable) is changing in one list will change the other same object
list_1 = ['History', 'Math', 'Physics', 'CompSci']
list_2 = list_1
print(list_1)
print(list_2)

list_1[0] = 'Art'

print(list_1)
print(list_2)

#hence if list is not to be modifies, we can use tuple
"""

# Tuple(Immutable, Hetrogenous)
# All methods and functions are same as of List, except the ones that mutate a list, because tuple is immutable
"""
tuple_1 = ('History', 'Math', 'Physics', 'CompSci')
tuple_2 = tuple_1

print(tuple_1)
print(tuple_2)

tuple_1[0] = 'Art'

print(tuple_1)
print(tuple_2)
"""

# Sets(Immutable, No duplicates, Unordered)
#Will remove all the duplicate elements, and print them in any order

cs_courses = {'History', 'Math', 'Physics', 'CompSci', 'Math'}
print(cs_courses)

art_courses = {'History', 'Math', 'Law', 'Design'}
print(cs_courses.intersection(art_courses))#common element in both the sets
print(cs_courses.difference(art_courses))#different elements
print(cs_courses.union(art_courses))#combination of both
#set is usefull for these kind of operations

#How to create an empty:- 

# Empty Lists
empty_list = []
empty_list = list()

# Empty Tuples
empty_tuple = ()
empty_tuple = tuple()

# Empty Sets
empty_set = {} # This isn't right! It's a dict
empty_set = set()
