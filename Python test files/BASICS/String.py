mes= 'hello world'
print("hello darkness my old friend")
#some functions
print(mes.capitalize())
print(mes.upper())
print(mes.lower())
print(mes[0:5])

#string formatting or concatination
gret = 'go karuna, karuna go'
text = '{}, {} why you come here'.format(mes,gret)
print(text)
#can also be done like this, f strings
ftext = f'{mes.capitalize()}, {gret} why you come here'
print(ftext)

#replace a string
new_mes = mes.replace('hello','bye')
print(new_mes)

#to see all the functions and attributes available with a var
print(dir(mes))

#to see all the functions and attributes and their description available for a class
print(help(str)) #have to pass class or datatype, can't pass var
print(help(str.lower))