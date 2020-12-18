import json

#load() is used to read json from a file and json. loads() to read json from a string

with open('states.json') as f:
    data = json.load(f)

#Printing the data 
"""
for st in data['states']:
    print(st['name'], st['abbreviation']) #we only print 2 elments
"""

for st in data['states']:
    del st['area_codes']

with open('test.json','w') as t:
    json.dump(data,t,indent=2)