tools

```sh
sudo apt install libssl-dev dwarves zstd syslinux dosfstools
```

build Linux

`.config`

```conf
CONFIG_SYSTEM_TRUSTED_KEYS=""
CONFIG_SYSTEM_REVOCATION_KEYS=""
```


User space: Busybox

- build static binary

```sh
make -j8
make CONFIG_PREFIX=/initramfs install
```

`/initramfs/init`

```
#!/bin/sh

/bin/sh
```

package using cpio

```sh
cd /initramfs
find . | cpio -o -H newc > init.cpio
```

fill a file with zeros

```sh
dd if=/dev/zero of=boot bs=1M count=50
```

create fat fs

```
mkfs -t fat boot
syslinux boot
mkdir dir
sudo mount boot dir
sudo cp init.cpio bzImage dir
```

boot into qemu

```sh
qmeu-system-x84_64 boot
```

```sh
/bzImage -initrd=/init.cpio
```
