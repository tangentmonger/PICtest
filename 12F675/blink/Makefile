#a test program for a 12F675 with LED sourcing current from RA5. Connect programmer and run 'make'

all:
	mkdir -p obj
	
    picc --chip=12F675 --ver --outdir=obj -P blink.c

	#assumes PK2DeviceFile.dat in same directory
    pk2cmd -PPIC12F675 -MC -MP -F obj/blink.hex -YP -E -T -X -R -GP3FF-3FF
    #take note of the OSSCAL value in 3FF in case it's accidentally overwritten

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
    #-Uxx: program xx as the OSCCAL value
    #GPval-val: read program memory

    #if you've lost the OSCAL value at location 3FF, this will replace it with a default value of 80
	#pk2cmd -PPIC12F675 -MC -MP -F obj/blink.hex -YP -E -T -GP3FF-3FF -U3480 
