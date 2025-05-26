CC=arm-none-eabi-gcc
CFLAGS=-Wall -mcpu=cortex-m3 -mthumb -nostdlib -ffreestanding
LDFLAGS=-T link.ld -nostdlib

all: blink.bin

blink.o: blink.c
	$(CC) $(CFLAGS) -c $< -o $@

startup.o: startup.s
	$(CC) $(CFLAGS) -c $< -o $@

blink.elf: blink.o startup.o link.ld
	$(CC) $(CFLAGS) blink.o startup.o $(LDFLAGS) -o $@

blink.bin: blink.elf
	arm-none-eabi-objcopy -O binary $< $@

clean:
	rm -f blink.o startup.o blink.elf blink.bin

.PHONY: all clean
