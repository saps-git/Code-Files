import csv

### READING FORM A CSV
"""
with open('names.csv','r') as csv_file:
    csv_reader = csv.reader(csv_file) #creating a reader to read from the files

    for line in csv_reader:
        print(line) #will give a list of all the values
        print(line[2]) #to print the email column
"""


### WRITING TO A CSV

"""
with open('names.csv','r') as csv_file:
    csv_reader = csv.reader(csv_file)

    with open('new.csv','w') as new_file:
        #csv_writer = csv.writer(new_file, delimiter='-') #delimiter, so they are seperated by '-' instead of ','
        csv_writer = csv.writer(new_file, delimiter= '\t')

        for line in csv_reader:
            csv_writer.writerow(line)

"""

## But when you open that file, ERROR

"""
with open ('new.csv','r') as new_file:
    #csv_reader = csv.reader(new_file)
    #This will print it out with the '\t' in place as a text, 
    #to change this we will have to explicitely state it in
    # the reader

    csv_reader = csv.reader(new_file,delimiter='\t') 

    for line in csv_reader:
        print(line)
"""

## READING THE CSV AS A DICTIONARY

## this will make the column name as keys, and hence easy to access
"""
with open('names.csv', 'r') as csv_file:
    csv_reader = csv.DictReader(csv_file)

    for line in csv_reader:
        #print(line)
        print(line['email']) #to print just the email column
"""

## To write csv files as dictionary
with open('names.csv', 'r') as csv_file:
    csv_reader = csv.DictReader(csv_file)

    with open('new_names.csv', 'w') as new_file:
        fieldnames = ['first_name', 'last_name']

        csv_writer = csv.DictWriter(new_file, fieldnames=fieldnames, delimiter='\t')

        csv_writer.writeheader()

        for line in csv_reader:
            del line['email']
            csv_writer.writerow(line)
