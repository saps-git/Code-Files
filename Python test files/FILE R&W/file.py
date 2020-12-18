#File Objects

##The Basics:
"""
## By default it opens on read mode
f = open("test.txt", "r") #if you open file this way, then you have to explicitely close it
f = open("test.txt", "w")
f = open("test.txt", "a")
f = open("test.txt", "r+") #read and write

print(f.name) 
print(f.mode) #mode it is opened with
f.close()
"""
##Reading Files (with context manager, best practice):
#with open("test.txt", "r") as f: #this will automatically close the file 

	##Small Files:
"""	
	#f_contents = f.read() 
	#print(f_contents)
"""

	##Big Files: (Print as list)
"""
	f_contents = f.readlines()
	print(f_contents)
"""

    ###With the extra lines: (will print one by one)
"""
	f_contents = f.readline() #print 1st line
	print(f_contents)
	
	f_contents = f.readline() #print 2nd line
	print(f_contents)
"""

	###Without the extra lines:
"""
	f_contents = f.readline()
	print(f_contents, end = '')
	
	f_contents = f.readline()
	print(f_contents, end = '')
"""

	# All the above methods might cause memory problems, as all 
	# the file contents wil be opened at once
	# Hence we can loop over them, one by one

	###Iterating through the file:
"""
	for line in f:
		print(line, end = '')
""" 

	#Using the earlier f.read() we can read line by line

	###Printing by characters:
"""
	f_contents = f.read(100) #100 chars at a time
	print(f_contents, end = '')
	
	f_contents = f.read(100)
	print(f_contents, end = '')
	
	f_contents = f.read(100) #once EOF is reached, it will return only empty string
	print(f_contents, end = '')
"""

	###Iterating through small chunks(when you dont know the size of the file ):
"""
	size_to_read = 100
	f_contents = f.read(size_to_read) #(equivalent to 'i=size_to_read')
	
	while len(f_contents) > 0: #(equivalent to 'while i>0:' )till EOF file is reached 
		print(f_contents,end="")
		f_contents = f.read(size_to_read) #(equivalent to 'i++') will take 100 char again to loop
"""

	###Iterating through small chunks, with 10 characters:
	
"""
	size_to_read = 10
	f_contents = f.read(size_to_read)

	while len(f_contents) > 0:
		print(f_contents, end = '*')
		f_contents = f.read(size_to_read)
"""

	#**  seek() & .tell()
"""
	size_to_read = 10
	
	f_contents = f.read(size_to_read)
	print(f_contents, end = '')
	
	print(f.tell()) #tells the current position on the file
	
	f.seek(0) #will again go to the 0th char for the next print statement
	
	f_contents = f.read(size_to_read)
	print(f_contents, end = '')
"""
	
#print(f.mode)
#print(f.closed)
#print(f.read())


##Writing Files:
###The Error:
"""
#with open("test.txt", "r") as f:
	#f.write("Test")
"""

###Writing Starts:
#with open("test2.txt", "w") as f: #if file doesn't exist, it will create it , if it exists it will overwrite it
"""	
	#pass #to just create a file
	f.write("Test")
	f.seek(0) #here it will overwrite the first one, as it goes to the starting of the file
	f.write("Test")
	f.seek(0)
	f.write("R") #here it will only replace the first letter with 'R'
"""

##Copying Files:
"""
with open("test.txt", "r") as rf: #will open this in read mode, as this is the one to be read from
	with open("test_copy.txt", "w") as wf: #to be written to
		for line in rf: #looping through all the lines in rf to printing them in wf
			wf.write(line)
"""

#Copying the/your image:
###The Error
"""
#with open("bronx.jpg", "r") as rf:
	#with open("bronx_copy.jpg", "w") as wf:
		#for line in rf:
			#wf.write(line)
"""
#inorder to work with images, they have to be opened in binary mode

###Copying the image starts, without chunks:
# have to use 'rb' & 'wb' (read binary and write binary) in place of 'r' & 'w' respectively
"""
with open("SS.png", 'rb') as rf:
	with open("SScopy.png", 'wb') as wf:
		for line in rf:
			wf.write(line)
"""

###Copying the image with chunks: (same as used to read in chunks, but with write statement included)
"""
with open("SS.png", "rb") as rf:
	with open("SS_copy.png", "wb") as wf:
		chunk_size = 4096
    	rf_chunk = rf.read(chunk_size)
    	while len(rf_chunk) > 0:
            wf.write(rf_chunk)
            rf_chunk = rf.read(chunk_size)
"""