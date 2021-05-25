import sys, os, re
import settings

def main():
	if (len(sys.argv) != 2):
		return
	path = sys.argv[1]
	regex = re.compile(".*\\.template$")
	if regex.match(path) == None:
		return print("put *.template file")
	if os.path.isfile(path) == False :
		return print("not exist file")
	f = open(path, mode="r", encoding='utf-8')
	template = "".join(f.readlines())
	file = template.format(title = settings.title, name = settings.name, surname = settings.surname, age = settings.age, profession = settings.profession)
	regex = re.compile(".template$")
	path = re.sub(regex, ".html", path)
	f = open(path, mode="w", encoding='utf-8')
	f.write(file)
	f.close()
if __name__ == '__main__':
	main()