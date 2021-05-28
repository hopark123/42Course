#!/usr/bin/env python3

import sys
import requests
from bs4 import BeautifulSoup

def main() :
	ahtml = requests.get("https://en.wikipedia.org/wiki/egg")
	soup = BeautifulSoup(ahtml.text, 'html.parser')
	text = soup.find(id='firstHeading').text
	main = soup.find("div", {"id":'mw-content-text'}).find_all('a')
	# print(len(main))
	for link in main :
		a = link.get('href')
		if type(a) is str and a.startswith('/wiki/') and not a.startswith('/wiki/File:'):
			print(a.split("/")[2])

if __name__ == '__main__':
	main()