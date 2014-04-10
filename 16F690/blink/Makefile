#a test program for a 16F690. Connect programmer and run 'make'

all:
	mkdir -p obj
	picc --chip=16F690 --outdir=obj -P blink.c
	#assumes PK2DeviceFile.dat in same directory
	pk2cmd -P -E -MC -MP -F obj/blink.hex -YP -YC -R -T

