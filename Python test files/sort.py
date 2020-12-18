
li = [9,2,1,3,7,6,4,8,5]

sli = sorted(li) #returns a sorted list, doesnt sort the original one
#returns any datatype as a sorted list
print(sli)

tup = (9,2,1,3,7,6,4,8,5)#returns any datatype as a sorted list
print(sorted(tup))

li.sort() #sorts, the original list, but returns none , as the original one is sorted
#sort() is a method of list class and can only be used with lists.
print(li)

#rli = sorted(li, reverse=True)
#print(rli)
#li.sort(reverse=True)
#print(li)


lit = [-6,-5,-4,1,2,3]
print(sorted(lit, key=abs)) #key, applies a function to them, then they are sorted accordingly

ch = ['aaaa','b','dafsdfs','76']
print(sorted(ch, key=len))


