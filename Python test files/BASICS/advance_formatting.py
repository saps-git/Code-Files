## dictionary formatting
"""
person = {'name': 'Jenn', 'age': 23}

sentence = 'My name is {} and I am {} years old.'.format(person['name'], person['age'])
print(sentence)
#also can be written as
sentence = 'My name is {0} and I am {1} years old.'.format(person['name'], person['age'])
print(sentence)
#also can be written as
sentence = 'My name is {0[name]} and I am {1[age]} years old.'.format(person, person) 
print(sentence)
#also can be written as
sentence = 'My name is {0[name]} and I am {0[age]} years old.'.format(person) #accessing two keys of the same dict, hence same placeholder
print(sentence)

sentence = 'My name is {name} and I am {age} years old.'.format(**person) #dictionary unpacking just like in kwargs
print(sentence)
"""

## list formatting
"""
l = ['jane',23]

sentence = 'My name is {0[0]} and I am {0[1]} years old.'.format(l)
print(sentence)
"""

## string formatting
"""
tag = 'h1'
text = 'This is a headline'

sentence = '<{0}>{1}</{0}>'.format(tag, text)
print(sentence)
"""

## class formatting
"""
class Person():

    def __init__(self, name, age):
        self.name = name
        self.age = age

p1 = Person('Jack', '33')

sentence = 'My name is {0.name} and I am {0.age} years old.'.format(p1) #using '.' as this is class object
print(sentence)
"""

## keyword formatting
"""
sentence = 'My name is {name} and I am {age} years old.'.format(name='Jenn', age='30')
print(sentence)
"""

## padding digits
"""
for i in range(1, 11):
    sentence = 'The value is {:02}'.format(i) #0 padding it to two digits
    print(sentence)
"""

## decimal formatting
"""
pi = 3.14159265
sentence = 'Pi is equal to {:2f}'.format(pi) #2 decimal places
print(sentence)
sentence = 'Pi is equal to {:3f}'.format(pi) #3 decimal places
print(sentence)
"""

## comma ',' formatting
"""
sentence = '1 MB is equal to {:,} bytes'.format(1000**2)
print(sentence)
sentence = '1 MB is equal to {:,.2f} bytes'.format(1000**2) #also adding 2 decimal places
print(sentence)
"""
"""
import datetime
my_date = datetime.datetime(2016, 9, 24, 12, 30, 45) #normal way
print(my_date)
"""
"""
## I want to print like March 01, 2016
sentence = '{:%B %d, %Y}'.format(my_date)
print(sentence)
"""

"""

# March 01, 2016 fell on a Tuesday and was the 061 day of the year.
sentence = '{0:%B %d, %Y} fell on a {0:%A} and was the {0:%j} day of the year'.format(my_date)
print(sentence)
"""