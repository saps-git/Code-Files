a = [1,2,3]
b = [1,2,3]
print(a==b) #compares only the value

print(id(a))
print(id(b))
print(a is b)#false since a & b are two different objects in memory, checks their ids
################################################################################################

#This types pf values will return false
# False Values:
    # False
    # None
    # Zero of any numeric type
    # Any empty sequence. For example, '', (), [].
    # Any empty mapping. For example, {}.
#Other than this everything will be true

condition = False

if condition:
    print('Evaluated to True')
else:
    print('Evaluated to False')
