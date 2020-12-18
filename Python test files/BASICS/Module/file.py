from my_module import find_index
import sys 

# print(sys.path) #will show list of dirs where python will for modules to import
# sys will start looking for the module from the dir you are in
# 
# If the module you want to import is not in the same directory, then you have to add it to the sys.path
# 
# we can add the module to the sys.path
# sys.path.append('/users/corey/desktop/my-module') 
# But this isn't a good aproach as we are adding it before all of our other imports
# and if it is hardcoded in other locations , we have  to manually add it everytime
#
# Hence we can add it to the next location where sys.path looks, that is pyhton path enviornment variable
#
# after that it looks at the standard library, some of its modules are:


import random
import math
import datetime,calendar
 
courses = ['History', 'Math', 'Physics', 'CompSci']

index = find_index(courses,'Math')
print(index)

#print(sys.path) #will show list of dirs where python will for modules to import, starting from the dir you are in

print(random.choice(courses)) #will keep printing random element form the list course

rads = math.radians(90)
print(rads)
print(math.sin(rads))

today = datetime.date.today()
print(today)

print(calendar.isleap(2020))