import random
import sys

def main():
	if len(sys.argv) == 3:
		sizeTotal = int(sys.argv[1])
		sizeFind  = int(sys.argv[2])
		la1 = []
		la2 = list(range(0,sizeTotal))
		for x in range(0, sizeFind):
			aux = random.randrange(0, len(la2))
			la1 += [la2[aux]]
			la2.pop(aux)
		ters = int(sizeFind/3)
		la3 = la1[0:ters]


		for x in range(0, (sizeFind*2)-ters):
			aux = random.randrange(0, len(la2))
			la3+= [la2[aux]]
			la2.pop(aux)

		la1.sort()
		#los que se añadiran
		f = open("arxiu1.txt", "w+")
		for item in la1:
			f.write("%d\n" % item)
		f.write("endfile")
		f.close()
		#los que se buscaran
		la3 = random.sample(la3, len(la3))
		f = open("arxiu2.txt", "w+")
		for item in la3:
			f.write("%d\n" % item)
		f.write("endfile")
		f.close()
	else:
		print('Usage:\nSon dos enteros, numero maximo del set, y numero de enteros a buscar')


if __name__ == "__main__":
	main()