from bs4 import BeautifulSoup
import requests

with open ('simple.html') as html_file:
    soup = BeautifulSoup(html_file, 'lxml')#passing the file into Beautifulsoup with lxml parser
"""
print(soup.prettify()) #pretify() to print the html with proper indentations and formatting

#match = soup.title #to grab the title, use the tag that you want to acess
match = soup.title.text #to access only the text from it
print(match)
"""

## RETURNING THE FIRST TAG, THAT MATCH THE ARGUMENT

"""
#match2= soup.div #will return the first div tag
#match2 = soup.find('div') #to find a particular tag, this will return the first tag

article = soup.find('div',class_='article') #to find a particular attribute of a tag, class_ with undercsore because, class is a keyword in python
#print(article) #print the whole article class


headline = article.h2.a.text #now grabbing the 'h2' from  the article class only, because we dont need the whole html (soup), then from it 'a' attribute, then text from it 
print(headline)

summary= article.p.text #grabbing the 'p' tag from it
print(summary)
"""

## RETURNING ALL THE TAGS, THAT MATCH THE ARGUMENT

for article in soup.find_all('div', class_='article'):
    headline = article.h2.a.text
    print(headline)

    summary = article.p.text
    print(summary)

    print()
