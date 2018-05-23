import urllib

from bs4 import BeautifulSoup

import mechanicalsoup

import re

def getunicode(soup):

	body=''

	if isinstance(soup, str):

		soup = soup.replace('&#39;',"'")

		soup = soup.replace('&quot;','"')

		soup = soup.replace('&nbsp;',' ')

		body = body + soup

	else:

		if not soup.contents:

			return ''

		con_list = soup.contents

		for con in con_list:

			body = body + getunicode(con)

	return body





def main():

	movie = str(input('Movie Name: '))

	movie_search = '+'.join(movie.split())

    

	base_url = 'http://www.imdb.com/find?q='

	url = base_url+movie_search+'&s=all'

    

	title_search = re.compile('/title/tt\d+')

    

	br = mechanicalsoup.StatefulBrowser()

    
    

                     

	br.open(url)



	link = br.find_link(url_regex = re.compile(r'/title/tt.*'))

	res = br.follow_link(link)

    

	soup = BeautifulSoup(res.text, "lxml")

    

	movie_title = getunicode(soup.find('title'))

	rate = soup.find('span',itemprop='ratingValue')

	rating = getunicode(rate)

   

	print (movie_title, rating)

    

    

if __name__ == '__main__':

    main()

    