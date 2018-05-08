import random

def main():
	la1 = []
	la2 = list(range(0,5000))
	for x in range(0, 1000):
		aux = random.randrange(0, len(la2))
		la1 += [la2[aux]]
		la2.pop(aux)
	la3 = la1[0:300]


	for x in range(0, 1700):
		aux = random.randrange(0, len(la2))
		la3+= [la2[aux]]
		la2.pop(aux)

	la1.sort()

	f = open("arxiu1.txt", "w+")
	for item in la1:
		f.write("%d " % item)
	f.close()
	f = open("arxiu2.txt", "w+")
	for item in la3:
		f.write("%d " % item)
	f.close()


if __name__ == "__main__":
	main()