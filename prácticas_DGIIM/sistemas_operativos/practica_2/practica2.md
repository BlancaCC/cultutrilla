# Práctica 2  

## Partición de un dispositivo USB pen drive   
Vamos ta trabajar sobre un archivo virtual   

### Creación de las particiones virtuales

- Creamso 
```
[root@localhost ~]# mknod /dev/loop0 b 7 0
[root@localhost ~]# mknod /dev/loop1 b 7 1

```

Creamso un archivo con diferentes tamaños

```
[root@localhost ~]# dd if=/dev/zero of=/root/archivo_SA20 bs=2k count=10000
10000+0 records in
10000+0 records out
20480000 bytes (20 MB) copied, 0.219228 s, 93.4 MB/s
[root@localhost ~]# dd if=/dev/zero of=/root/archivo_SA30 bs=3k count=10000
10000+0 records in
10000+0 records out
30720000 bytes (31 MB) copied, 0.260275 s, 118 MB/s

```
El archivo /dev/zero Es un archivo especial de linux que proove tantos caracteres nullos como queramos. 

- ahora asociamos cada uno de los archivos anteriores creados a cada una de las particiones

```
[root@localhost ~]# losetup /dev/loop0 /root/archivo_SA20 
[root@localhost ~]# losetup /dev/loop1 /root/archivo_SA30 
```


- comprobemos los discos virtuales creados con la siguiente orden. 
```
[root@localhost ~]# fdisk -l /dev/loop0

Disk /dev/loop0: 20 MB, 20480000 bytes
255 heads, 63 sectors/track, 2 cylinders, total 40000 sectors
Units = sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disk identifier: 0x00000000

Disk /dev/loop0 doesn't contain a valid partition table

```

(Tambié se podía haber optado por haber introducido un pendrive, hemos prescincido de esa opción :)

## Formateo lógico  
Procedamos a formatear el primer disco con la instrucción `mke2fs`

```
[root@localhost ~]# mke2fs -c /dev/loop0 -t exp3  
mke2fs 1.41.12 (17-May-2010)
Filesystem label=
OS type: Linux
Block size=1024 (log=0)
Fragment size=1024 (log=0)
Stride=0 blocks, Stripe width=0 blocks
5016 inodes, 20000 blocks
1000 blocks (5.00%) reserved for the super user
First data block=1
Maximum filesystem blocks=20709376
3 block groups
8192 blocks per group, 8192 fragments per group
1672 inodes per group
Superblock backups stored on blocks: 
	8193

Checking for bad blocks (read-only test): done                                
Writing inode tables: done                            
Writing superblocks and filesystem accounting information: done

This filesystem will be automatically checked every 38 mounts or
180 days, whichever comes first.  Use tune2fs -c or -i to override.

```


Para la segunda ejecutamos
`root@localhost ~]# mke2fs -c /dev/loop1 -T exp4 `  

## Ajuste de parámetros configurables de un SA y comprobación de errores  

Para obtener información relevante sobre SA ejecutamos `tune2fs -l nombre`

ejemplo : 
```
[root@localhost ~]# tune2fs -l /dev/loop0
tune2fs 1.41.12 (17-May-2010)
Filesystem volume name:   <none>
Last mounted on:          <not available>
Filesystem UUID:          37d08cde-6ade-4980-9900-d75b8443a7fa
Filesystem magic number:  0xEF53
Filesystem revision #:    1 (dynamic)
Filesystem features:      has_journal ext_attr resize_inode dir_index filetype sparse_super large_file
Filesystem flags:         signed_directory_hash 
Default mount options:    (none)
Filesystem state:         clean
Errors behavior:          Continue
Filesystem OS type:       Linux
Inode count:              1264
Block count:              5000
Reserved block count:     250
Free blocks:              3885
Free inodes:              1253
First block:              0
Block size:               4096
Fragment size:            4096
Reserved GDT blocks:      1
Blocks per group:         32768
Fragments per group:      32768
Inodes per group:         1264
Inode blocks per group:   79
Filesystem created:       Mon Dec 10 17:30:24 2018
Last mount time:          n/a
Last write time:          Mon Dec 10 17:30:24 2018
Mount count:              0
Maximum mount count:      29
Last checked:             Mon Dec 10 17:30:24 2018
Check interval:           15552000 (6 months)
Next check after:         Sat Jun  8 18:30:24 2019
Reserved blocks uid:      0 (user root)
Reserved blocks gid:      0 (group root)
First inode:              11
Inode size:	          256
Required extra isize:     28
Desired extra isize:      28
Journal inode:            8
Default directory hash:   half_md4
Directory Hash Seed:      bae1d2df-811a-409e-84d2-232e11d04643
Journal backup:           inode blocks

```

Podemos observar en la primera línea: `Filesystem volume name:   <none>`

Para poder asignarle un nombre bastará con asignarle una etiqueta: 
```
[root@localhost ~]# tune2fs -L LABEL_ext3 /dev/loop0
tune2fs 1.41.12 (17-May-2010)

```

Para comprobar la consistencia del sistema de archivos usaremos `fsck`

## Modifica el archivo para que loop0 y loop1 se monten automáticamente nuestros dos SA

Para ello he añadido al final del archivo /dev/fstab las siguientes ĺíneas

```
loop0                                           /dev/loop0      auto    defaults        0 0
loop1                                           /dev/loop1      auto    defaults        0 0

```


Cómo he conseguido montar mi sistema 
`[root@localhost ~]# mount none /mnt/ -t hostfs -o /home/blanca/SO/modulo_i/fedora/paquetes/`


Donde mount es un directorio al que hemos creado para montar 
