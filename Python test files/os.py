import os
import sys
from datetime import datetime

#Basic

print(os.getcwd()) #current working dir
"""
os.chdir('/home/saptarshi/Downloads/Notes') #change the cwd
print(os.getcwd())

os.rename('fax','DBMS (www.gate2016.info).pdf') #old name, new name

print(os.listdir()) #list files in that dir
"""

#making and removing directories
"""
os.mkdir('os-demo') #to create single directory
os.makedirs('os-ola/sub') #to create multiple directory (mainly use this)

os.rmdir('os-ola/sub') #remove one dir at a time,\the last one
os.removedirs('os-ola/sub') #removes the whole tree
"""

#prints useful data regarding a file
"""
print(os.stat('DBMS.pdf').st_mtime) 
#to have a more clear look
mod_time = os.stat('DBMS.pdf').st_mtime
print(datetime.fromtimestamp(mod_time))
"""

#to see the dir tree
"""
for dirpath, dirname, filename in os.walk('/home/saptarshi/Downloads'): #os.walk returns 3 parameters dir path, dirs and files inside that dir
    print('current path', dirpath)
    print('directories:', dirname)
    print('files:', filename)
    print()
"""
#create a path
print(os.environ.get('HOME')) #printing env
filepath = os.path.join(os.environ.get('HOME'),'test.txt') #path.join automatically joins two strings and makes a path
print(filepath)

#other os.path functions
""" 
print(os.path.basename('/tmp/test.txt'))# returns only filename
print(os.path.dirname('/tmp/test.txt')) #returns only dir name
print(os.path.split('/tmp/test.txt')) #split in a tuple

print(os.path.exists('/tmp/test.txt')) #wether it exists or not in the file system
print(os.path.isdir('/tmp/test.txt')) #is it a dir
print(os.path.isfile('/tmp/test.txt')) #is it a file
print(os.path.splitext('/tmp/test.txt')) #spliting the base and its extension
"""