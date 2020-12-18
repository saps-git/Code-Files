"""
def hello():
    return "heoo"

print(hello().upper()) #function chaninng

#######################################################################################################

#passing parameter
def gret(greeting,name = "master"): #if no name is passed, it will print the default(here master)
    return "{} {}".format(greeting,name)

print(gret("ola","senor"))

#######################################################################################################
"""
# *args **kwargs

def hello_f(*args, **kwargs):
    print(args) #will convert into a tuple , it is positional argument
    print(kwargs) #will convert into dictionary, it is keyword argument 

hello_f('math','art', name='john', age=22) #evey argument will be treated as *arg(postional), untill a dictionary is explicitly given (keyword)

courses = [1,2,3,4]
info = {'name': 'john', 'age': 22}

hello_f(*courses,**info)
#######################################################################################################

#EXAMPLE FUNCTIONS

# Number of days per month. First value placeholder for indexing purposes.
month_days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def is_leap(year):
    """Return True for leap years, False for non-leap years."""

    return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)


def days_in_month(year, month):
    """Return number of days in that month in that year."""

    if not 1 <= month <= 12:
        return 'Invalid Month'

    if month == 2 and is_leap(year):
        return 29

    return month_days[month]

print(days_in_month(2017,2))

