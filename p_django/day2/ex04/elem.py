#!/usr/bin/python3

class Text(str):
	def __str__(self):
		return super().__str__().replace('\n', '\n<br />\n')


class Elem:
	class ValidationError :
		def __init__(self) -> None:
			super().__init__("elem error.")

	def __init__(self, tag='div', attr={}, content=None, tag_type='double'):
		self.tag = tag
		self.attr = attr
		self.content = content
		self.tag_type = tag_type
		[...]
	def __str__(self):
		[...]
		if self.tag_type == 'double':
			[...]
		elif self.tag_type == 'simple':
			[...]
		return result

	def __make_attr(self):
		result = ''
		for pair in sorted(self.attr.items()):
			result += ' ' + str(pair[0]) + '="' + str(pair[1]) + '"'
		return result

	def __make_content(self):
		if len(self.content) == 0:
			return ''
		result = '\n'
		for elem in self.content:
			result += [...]
		return result

	def add_content(self, content):
		if not Elem.check_type(content):
			raise Elem.ValidationError
		if type(content) == list:
			self.content += [elem for elem in content if elem != Text('')]
		elif content != Text(''):
			self.content.append(content)

	@staticmethod
	def check_type(content):
		return (isinstance(content, Elem) or type(content) == Text or
				(type(content) == list and all([type(elem) == Text or
												isinstance(elem, Elem)
												for elem in content])))
	def test():
		html = Elem('html', content=[
					Elem('head', content=Elem(
						'title', content=Text('"Hello ground!"'))),
					Elem('body', content=[Elem('h1', content=Text('"Oh no, not again!"')),
										Elem('img', {'src': 'http://i.imgur.com/pfp3T.jpg'}, tag_type='simple')])])
		print(html)

if __name__ == '__main__':
	[...]
