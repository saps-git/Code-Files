import json 

#sample json as a python string
people_string = """ 
{
    "people": [
        {
            "name":"saptarshi hore",
            "year": "third",
            "section": "k2",
            "email": "sap@jf"
        },
        {
            "name": "rohan",
            "year": "third",
            "section": "is2",
            "email": "jgsf@gd"
        }
    ]
}
"""

## the top level key, is a list of values, that is "people" 
## JSON gives values in  a dictionary format, here the first key in that dictionary is "people"
## the key "people" its value is a list 
## a list which contains dictionary of elements

data = json.loads(people_string)
#print(data) #json converts it into a py dict
#print(data['people']) #printing the value of the first key

#printing the values of a json
"""
for val in data['people']: #fetching from the value of key
    #print(val)
    print(val['name']) #print the first value from 'people'
"""

#to delete a particular key
"""
for val in data['people']:
    del val['email']
"""

#to convert  a string to json (dumps)

new_string = json.dumps(data, indent=2) #indent=2 will give it a two spaces on every new level
#new_string = json.dumps(data, indent=2,sort_keys=True) #will sort all the keys in alphabatical order
print(new_string)