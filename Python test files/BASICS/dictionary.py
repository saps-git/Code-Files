#Dictionary(Mutable, Hetrogenous)
std = {'name':'saptarshi', 'age':23, 'courses': ['Maths','Science']}
print(std)
print(std['name']) #values can only be accessed by their keys
print(std['courses'])

print(std.get('phone','not found')) #if the given key is not found , then the default value(here 'not found') is printed
print(std.get('age','not found'))

#update values, will overwrite
std['name']= 'rohan'
std['phone']= '23465'
print(std)
#To assign multiple values at once
std.update({'name':'sheldon', 'age':22, 'phone':'55-234-345'})
print(std)

#del std['age'] #deleting a partiular value
#print(std)

ag = std.pop('age') #will pop a certain value
print(ag)

print(len(std)) #number of keys present
print(std.keys())
print(std.values())
print(std.items()) #both keys and values

for i in std: #this will only print keys
    print(i)

for v in std.values(): #to loop thru and print only values
    print(v)

for k,v in std.items(): #to loop thru and print both keys and values
    print(k,v)
