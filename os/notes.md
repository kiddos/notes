# boot

When the computer boots, the BIOS will load the boot sector. It is a standard location, which is the first sector of the disk (cylinder 0, head 0, sector 0), and it takes 512 bytes

the BIOS will check that the byte 511 and 512 are 0xAA55

```
nasm -f bin simple_boot_sector.asm -o simple_boot_sector.bin
```
