#!/usr/bin/python3

class Inter:
	def __init__(self, Name=None) -> None:
		if Name is None:
			self.Name = "My name? I’m nobody, an intern, I have no name."
		else:
			self.Name = Name
	# self.Name = "My name? I’m nobody, an intern, I have no name." if Name is None else Name ?? 이렇게하면 오류안나는데 그 이유가 무엇인가

	def __str__(self) -> str:
		return self.Name

	def work(self):
		raise Exception("I’m just an intern, I can’t do that...")

	def make_coffee(self):
		return (self.Coffee())

	class Coffee:
		def __str__(self):
			return "This is the worst coffee you ever tasted."


def main():
	none = Inter()
	Mark = Inter("Mark")
	print(none)
	print(Mark)
	print(Mark.make_coffee())
	try:
		none.work()
	except Exception as e:
		print(e)

if __name__ == '__main__':
	main()
