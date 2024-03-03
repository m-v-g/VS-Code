FILENAME   = main
MCU        = atmega8
PROGRAMMER = STK500
PORT       = COM13


COMPILE = avr-gcc -Wall -Os -mmcu=$(MCU)


default: compile upload clean

compile:
	$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	$(COMPILE) -o $(FILENAME).elf $(FILENAME).o
	avr-objcopy -O ihex $(FILENAME).elf $(FILENAME).hex

upload:
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -U flash:w:$(FILENAME).hex:i

clean:
	avr-size --format=avr --mcu=$(MCU) $(FILENAME).elf
	rm $(FILENAME).o
	rm $(FILENAME).elf
	