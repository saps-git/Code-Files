import requests

#To get or request info to a website
"""
r = requests.get('https://xkcd.com/353/')
print(r)
#print(dir(r)) #to see the attributes available
#print(help(r)) #same as above but much more detailed
"""
#to download a image
"""
r = requests.get('https://imgs.xkcd.com/comics/python.png')

with open('img.png','wb') as im:
    im.write(r.content) #r.content gets the byte info a file
"""

#details of the rquested element
"""
r= requests.get('https://imgs.xkcd.com/comics/python.png')
print(r.status_code)
#200= success 300= redirects 400=client errors, no permissions #500= server error, server crash

print(r.ok) #below 400 true, above false
print(r.headers) #headers available
"""

#to add parameters
"""
add= {'page':2,'count':25}
r= requests.get('https://httpbin.org./get',params=add)

print(r.url) #to see the url
print(r.text)
"""

#POST data
"""
add= {'name':'corey','password':'testing'}
r= requests.post('https://httpbin.org./post',data=add)

#print(r.url)
#print(r.text)

r_dict = r.json()
print(r_dict['form'])
"""

