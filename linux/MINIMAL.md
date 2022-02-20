1. prepare busybox

- download source

```
curl https://busybox.net/downloads/busybox-1.35.0.tar.bz2 | tar xjf -
cd busybox-1.35.0
```

- build as static binary

```shell
make O=../build/busybox-x86 defconfig
make O=../build/busybox-x86 menuconfig
```

```
-> Busybox Settings
  -> Build Options
[ ] Build BusyBox as a static binary (no shared libs)
```

```
cd ../build/busybox-x86
make -j$(nproc)
make install
```

2. prepare initramfs

```
mkdir -pv initramfs/busybox-x86/{bin,sbin,etc,proc,sys,usr/{bin,sbin}}
cd initramfs/busybox-x86
cp -av build/busybox-x86/_install/* .
```

create `init` script

```shell
#!/bin/sh
 
mount -t proc none /proc
mount -t sysfs none /sys
 
echo -e "\nBoot took $(cut -d' ' -f1 /proc/uptime) seconds\n"
 
exec /bin/sh
```

```
chmod +x init
```

3. prepare cpio

```
cd initramfs/busybox-x86
find . -print0 \
    | cpio --null -ov --format=newc \
    | gzip -9 > $TOP/obj/initramfs-busybox-x86.cpio.gz
```

4. clone linux repo

```shell
git clone https://github.com/torvalds/linux.git
```

```shell
make O=../build/linux-x86 alldefconfig
```

turn on 8250/16550 serial port

```
make O=../build/linux-x86 nconfig
```

```
-> Device Drivers
  -> Character devices
    -> Serial drivers

    [*] 8250/16550 and compatible serial support
    [*] Console on 8250/16550 and compatible serial port
```

enable iniramfs


```
-> General setup
  [*] Initial RAM filesystem and RAM disk (initramfs/initrd) support
```


compile

```
make O=../build/linux-x86 -j$(nproc)
```

5. boot


```shell
qemu-system-x86_64 \
    -kernel build/linux-x86/arch/x86_64/boot/bzImage \
    -initrd build/initramfs-busybox-x86.cpio.gz \
    -nographic -append "console=ttyS0"
```
