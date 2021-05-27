import requests
import json
import dewiki
import sys

class my_wiki():

	class wiki_Exception(Exception) :
		def __init__(self, msg = "") :
			super()__init__(self, msg)

	URL : 'https://en.wikipedia.org/w/api.php'
	PARAM = {
		"action" : "query"
		"format" : "json"
		"rvprop" : "content"
		"prop" : "revisions"
		"titles" : search_str
		page  : page
		redirects = true
	}
	
	def __init__(self, serch=None) :
		if isinstance(serach, str) and search.strip() is None :
			self.filename = "_"join(serach.split()) + ".wiki"
		elif (serch is None) :
			raise my_wiki.wiki_Exception("YYou must specify something to search")

		




def main() :
	my_wiki()

if __name__ == '__main__':
	main()

# pip freeze > requirement.txt