from bs4 import BeautifulSoup
import requests


source = requests.get('http://coreyms.com').text #getting request from a site, in text format

soup = BeautifulSoup(source, 'lxml') #passing it through the beautiful soup and parsing with lxml parser
#print(soup.prettify())

### FOR FINDING DATA OF ONE ARTICLE
"""
article = soup.find('article') #finding a particular tag

#print(article.prettify())

##PRINTING ONE HEADLINE
headline = article.h2.a.text
print(headline)
print()

##PRINTING ONE SUMMARY
summary = article.find('div',class_='entry-content').p.text
print(summary)
print()


#PRINTING THE LINK TO THE VIDEO
link = article.find('iframe', class_='youtube-player')['src'] #unlike getting the text, we want to get the value of the src, hence we use it like a dictionary
#print(link)

##splitting the link and grabbing values to get the vdo ID
vid_link_id = link.split('/')[4]
vid_link_id = vid_link_id.split('?')[0]
#print(vid_link_id)

##CREATING OWN YOUTUBE LINK (that can be used as url)
yt_link = f'https://youtube.com/watch?v={vid_link_id}'  #youtube links are formatted this way only, vid_link is our vdo id here
print(yt_link)
"""


###FOR FINDING SIMILAR DATA IN THE WHOLE SITE
"""
for article in soup.find_all('article'):

    headline = article.h2.a.text
    print(headline)
    print()

    date = article.find('p', class_='entry-meta').time.text
    name = article.find('p', class_='entry-meta').a.span.text
    details = f'{date} by {name}'
    print(details)
    print()

    summary = article.find('div', class_="entry-content").p.text
    print(summary)
    print()

    link = article.find('iframe',class_='youtube-player')['src'] 
    vid_link_id = link.split('/')[4] 
    vid_link_id = vid_link_id.split('?')[0]

    yt_link = f'https://youtube.com/watch?v={vid_link_id}'
    print(yt_link)
    print()
"""

### SOMETIMES SOME DATA WILL BE MISSING IN A CONTINUATION, HERE THERE IS ONE BLOCK WHERE THERE IS NO VIDEO
### HENCE THAT SHOULD NOT BREAK OUR SCRAPPER
### THEREFORE WE WILL USE TRY CATCH BLOCK TO PASS THROUGH IT

for article in soup.find_all('article'):

    headline = article.h2.a.text
    print(headline)
    print()

    date = article.find('p', class_='entry-meta').time.text
    name = article.find('p', class_='entry-meta').a.span.text
    details = f'{date} by {name}'
    print(details)
    print()

    summary = article.find('div', class_="entry-content").p.text
    print(summary)
    print()

    try:
        link = article.find('iframe',class_='youtube-player')['src'] 
        vid_link_id = link.split('/')[4] 
        vid_link_id = vid_link_id.split('?')[0]

        yt_link = f'https://youtube.com/watch?v={vid_link_id}'
    except Exception as e:
        #pass #you can pass, but that will just pass over it, we want to return some value or print that statement to
        yt_link = None

    print(yt_link)
    print()

