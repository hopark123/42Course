#!/usr/bin/env python3

import requests
import json
import dewiki
import sys
	
# a = get(url, param)
# data = json(a)
# data[action][pages][prop]
# 	[0][*]

class my_wiki():

	class wiki_Exception(Exception) :
		def __init__(self, msg = "") :
			super().__init__(msg)

	URL = 'https://en.wikipedia.org/w/api.php'
	PARAM = {
		"action": "parse",
		"prop": "wikitext",
		"format": "json",
		"redirects": "true"
	}
	
	def __init__(self, search=None) :
		if isinstance(search, str) and not search.strip() is None:
			self.filename = "_".join(search.split()) + ".wiki"
			self.PARAM['page'] = search.lower().strip()
			# self.PARAM['gpssearch'] = search.lower().strip()
		else :
			raise my_wiki.wiki_Exception("You must specify something to search")
	
	def search(self) :
		res = requests.get(url = self.URL, params = self.PARAM)
		my_wiki.wiki_Exception(res.raise_for_status())
		return res.json()

	def get_text(self, data) -> str:
		print(data["parse"])
		return dewiki.from_string(data["parse"]["wikitext"]["*"])

	def make_file(self) :
		data = self.search()
		data_string = self.get_text(data)
		f = open(self.filename, 'w')
		f.write(data_string)
		f.close()

def main() :
	if (len(sys.argv) == 2) :
		try :
			wiki = my_wiki(sys.argv[1])
		except Exception as e :
			print(e)
		# try :
		wiki.make_file()
		# except Exception as e :
			# print(e)


if __name__ == '__main__':
	main()

# pip freeze > requirement.txt
