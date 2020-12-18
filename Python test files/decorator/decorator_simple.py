##here we will divide two numbers, but it should always return greater/smaller

#decorator function
def smart_div(func): #defining the decorator, it takes func as parameter
    def inner(a,b): #the wrapper function that does the original job NOTE: the function should have the same number of parameter as the original function
        if a<b:
            a,b = b,a
        return func(a,b) #now returning to the initial function or calling the initial function after the job has been done here
    return inner #returning the wrapper function


@smart_div #calling the decorator function , the decorator function defination needs to be above this 
def div(a,b):
    """
    #this part is in the decorator function, which can be reused

    if a<b:
        a,b = b,a

    """
    print(a/b)


div(2,4)
