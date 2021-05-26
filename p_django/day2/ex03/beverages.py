class HotBeverage :
	def __init__(self) -> None:
		self.price = 0.30
		self.name = "hot beverage"
	def description(self) :
		return "Just some hot water in a cup."
	def __str__(self) -> str:
		tempplate = (
			"name : {name}\n"
			"price : {price:0.2f}\n"
			"description : {description}"
		)
		return tempplate.format(name = self.name, price = self.price, description = self.description())
	#TODO: format으로 하는게 dry?
class Coffee(HotBeverage) :
	def __init__(self) -> None:
		self.name = "coffee"
		self.price = 0.40
	def description(self):
		return "A coffee, to stay awake."

class Tea(HotBeverage) :
	def __init__(self) -> None:
		self.price = 0.30
		self.name = "tea"
	def description(self):
		return super().description()
	#TODO: price 설정?
	#굳이 ? super().__init__()

class Chocolate(HotBeverage) :
	def __init__(self) -> None:
		self.name = "chocolate"
		self.price = 0.50
	def description(self):
		return "Chocolate, sweet chocolate..."

class Cappuccino(HotBeverage) :
	def __init__(self) -> None:
		self.name = "cappuccino"
		self.price = 0.45
	def description(self):
		return "Un po’ di Italia nella sua tazza!"

def main() :
	print(HotBeverage())
	print(Coffee())
	print(Tea())
	print(Chocolate())
	print(Cappuccino())

if __name__ == '__main__' :
	main()