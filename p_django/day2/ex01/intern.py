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
	try:
		none = Inter()
	except Exception as e:
		print('1 case 예외가 발생했습니다.', e)
	try:
		Mark = Inter("Mark")
	except Exception as e:
		print('2 case 예외가 발생했습니다.', e)
	try:
		print(none)
	except Exception as e:
		print('3 case 예외가 발생했습니다.', e)
	try:
		print(Mark)
	except Exception as e:
		print('4 case 예외가 발생했습니다.', e)
	try:
		print(Mark.make_coffee())
	except Exception as e:
		print('5 case 예외가 발생했습니다.', e)
	try:
		none.work()
	except Exception as e:
		print('6 case 예외가 발생했습니다.', e)

if __name__ == '__main__':
	main()
