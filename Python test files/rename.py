import os

os.chdir('/path/to/files/')

# Am I in the correct directory?
# print(os.getcwd())

# print(dir(os))

# Print all the current file names
for f in os.listdir():
    # If .DS_Store file is created, ignore it
    if f == '.DS_Store':
        continue

    file_name, file_ext = os.path.splitext(f) #splitting the extension, so it doesn't change
    # print(file_name)

    # One way to do this
    f_title, f_course, f_number = file_name.split('-') #to split on a '-', since it will split into 3 parts, hence we will make 3 var to store them

    # print('{}-{}-{}{}'.format(f_number, f_course, f_title, file_ext)) #to alter the file name, and see how they work

    # Need to remove whitespace
    f_title = f_title.strip()
    f_course = f_course.strip()
    # f_number = f_number.strip()

    # print('{}-{}-{}{}'.format(f_number, f_course, f_title, file_ext))

    # Want to remove the number sign?
    # f_number = f_number.strip()[1:] #to  strip the '#' or any sign in front and store it to the f_number var

    # One thing I noticed about this output is that if it was sorted by filename
    # then the 1 and 10 would be next to each other. How do we fix this? One way we can fix this is to pad
    # the numbers. So instead of 1, we'll make it 01. If we had hundreds of files then this would maybe need to be 001.
    # We can do this in Python with zfill
    f_number = f_number.strip()[1:].zfill(2) #will pad the digit to 2 digits, that is , if it is 1, then it will make it 01, if it is 10, it will remain same

    # print('{}-{}-{}{}'.format(f_number, f_course, f_title, file_ext))

    # You have the power to reformat in any way you see fit
    print('{}-{}{}'.format(f_number, f_title.strip(), file_ext.strip()))

    new_name = '{}-{}{}'.format(file_num, file_title, file_ext)

    os.rename(fn, new_name) #rename


# print(len(os.listdir()))