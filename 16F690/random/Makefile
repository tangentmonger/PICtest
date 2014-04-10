#a test program for random number generation on a 16F690. Connect programmer and run 'make'

all:
	mkdir -p obj
	picc --chip=16F690 --outdir=obj -P random.c
	#assumes PK2DeviceFile.dat in same directory
	pk2cmd -P -E -MC -MP -F obj/random.hex -YP -YC -R -T

