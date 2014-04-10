#a test program for a 12F675 with LED sourcing current from RA5. Connect programmer and run 'make'

all:
	mkdir -p obj
	picc --chip=12F675 --outdir=obj -P random.c
	#assumes PK2DeviceFile.dat in same directory
	pk2cmd -PPIC12F675 -MC -MP -F obj/random.hex -YP -E -T -GP3FF-3FF
    #take note of OSSCAL value at 3FF, it's possible to accidentally overwrite it

    #-P: specify chip
    #-E: erase flash device
    #-MC: program configuration memory
    #-MP: program program memory
    #-F: file to upload
    #-YP: verify program memory
    #-YC: verify configuration memory
    #-R: release /MCLR after operations
    #-T: power target after operations
    #-X: VDD first program entry (not required for PIC16)
    #-GI: read ID
    #-GC: read config word (looks ok, changes as expected)
    #-L16: program at slowest speed (makes no difference, default fast is fine)
    #-U8C: program 8C as the OSCCAL valie
    #GPval-val: read program memory


    #command to replace a lost OSSCAL value with a default of 80:
	#pk2cmd -PPIC12F675 -MC -MP -F obj/random.hex -YP -E -T -GP3FF-3FF -U3480 
