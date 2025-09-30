# Linux XIP on the RP2350

This is an attempt to use eXecute-In-Place by running stuff from the flash instead of loading them to RAM.

This repository is probably not what you are looking for. Please, refer to the original work here (which does not use XIP): https://github.com/Mr-Bossman/pi-pico2-linux

I do not plan to upstream any of this as this is mostly some hacks for learning and experimentation purposes.

It works on a Pimoroni Pico Plus 2, but should be easily portable to other boards featuring Flash and PSRAM.

## TODO

- [x] improve partition table handling
- [x] XIP_KERNEL
- [x] use CRAMFS or similar instead of initramfs
- [ ] execute FDPIC-ELF or BFLT binaries with XIP
- [ ] use internal SRAM

## Output

The output is slightly different than the original work. Notice we have a bit more memory available and we can actually run some of the busybox utilities.

```
PSRAM setup complete. PSRAM size 0x800000 (8388608)
Jumping to 0x117ffffc, aligned from 0x117ffffc
Function pointers: 0x82 0x80

Rom dump:
10010000   d0 0d fe ed 00 00 07 02  00 00 00 38 00 00 05 e8  |...........8....|
10010010   00 00 00 28 00 00 00 11  00 00 00 10 00 00 00 00  |...(............|
00000030
Kernel dump:
10200000   6f 00 c0 05 00 00 00 00  00 00 00 00 00 00 00 00  |o...............|
10200010   00 30 e7 00 00 00 00 00  00 00 00 00 00 00 00 00  |.0..............|
00000030

Ram dump:
11000000   9d 6e ac 57 00 00 00 00  00 00 00 00 00 00 00 00  |.n.W............|
11000010   00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000030

Jumping to kernel at 10200000 and DT at 10010000
If you are using USB serial, please connect over the hardware serial port.
[    0.000000] Linux version 6.15.0 (marco@fedora) (riscv32-buildroot-linux-uclibc-gcc.br_real (Buildroot 2025.05-541-g7980c0fb90) 14.3.0, GNU ld (GNU Binutils) 2.43.1) #1 Tue Sep 30 16:35:36 CEST 2025
[    0.000000] Machine model: riscv-minimal-nommu,qemu
[    0.000000] earlycon: pl11 at MMIO32 0x40070000 (options '')
[    0.000000] printk: legacy bootconsole [pl11] enabled
[    0.000000] OF: reserved mem: Reserved memory: No reserved-memory node in the DT
[    0.000000] Zone ranges:
[    0.000000]   Normal   [mem 0x0000000011000000-0x000000002007ffff]
[    0.000000] Movable zone start for each node
[    0.000000] Early memory node ranges
[    0.000000]   node   0: [mem 0x0000000011000000-0x00000000117fffff]
[    0.000000]   node   0: [mem 0x0000000020000000-0x000000002007ffff]
[    0.000000] Initmem setup node 0 [mem 0x0000000011000000-0x000000002007ffff]
[    0.000000] On node 0, zone Normal: 59392 pages in unavailable ranges
[    0.000000] On node 0, zone Normal: 896 pages in unavailable ranges
[    0.000000] riscv: base ISA extensions aim
[    0.000000] riscv: ELF capabilities aim
[    0.000000] Ticket spinlock: enabled
[    0.000000] Kernel command line: earlycon=pl011,mmio32,0x40070000 console=ttyAMA0 root=mtd:rootfs rootfstype=cramfs
[    0.000000] printk: log buffer data + meta data: 65536 + 204800 = 270336 bytes
[    0.000000] Dentry cache hash table entries: 1024 (order: 0, 4096 bytes, linear)
[    0.000000] Inode-cache hash table entries: 1024 (order: 0, 4096 bytes, linear)
[    0.000000] Built 1 zonelists, mobility grouping off.  Total pages: 2176
[    0.000000] mem auto-init: stack:all(zero), heap alloc:off, heap free:off
[    0.000000] SLUB: HWalign=64, Order=0-1, MinObjects=0, CPUs=1, Nodes=1
[    0.000000] NR_IRQS: 64, nr_irqs: 64, preallocated irqs: 0
[    0.000000] riscv-intc: 32 local interrupts mapped
[    0.000000] clint: clint@d0000000: timer running at 1000000 Hz
[    0.000000] clocksource: clint_clocksource: mask: 0xffffffffffffffff max_cycles: 0x1d854df40, max_idle_ns: 3526361616960 ns
[    0.000073] sched_clock: 64 bits at 1000kHz, resolution 1000ns, wraps every 2199023255500ns
[    0.013561] Console: colour dummy device 80x25
[    0.021806] Calibrating delay loop (skipped), value calculated using timer frequency.. 2.00 BogoMIPS (lpj=4000)
[    0.034206] pid_max: default: 4096 minimum: 301
[    0.042347] Mount-cache hash table entries: 1024 (order: 0, 4096 bytes, linear)
[    0.052335] Mountpoint-cache hash table entries: 1024 (order: 0, 4096 bytes, linear)
[    0.175380] Memory: 6032K/8704K available (2491K kernel code, 302K rwdata, 241K rodata, 144K init, 126K bss, 2464K reserved, 0K cma-reserved)
[    0.211039] devtmpfs: initialized
[    0.323127] clocksource: jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 7645041785100000 ns
[    0.335739] posixtimers hash table entries: 512 (order: -1, 2048 bytes, linear)
[    0.345694] futex hash table entries: 16 (order: -5, 192 bytes, linear)
[    0.409676] Serial: AMBA PL011 UART driver
[    0.561416] clocksource: Switched to clocksource clint_clocksource
[    1.624085] workingset: timestamp_bits=30 max_order=11 bucket_order=0
[    1.786392] irq-simple: Interrupt controller register, nr_irqs 512
[    1.852039] Serial: 8250/16550 driver, 1 ports, IRQ sharing disabled
[    1.953035] physmap-flash 10800000.flash: physmap platform flash device: [mem 0x10800000-0x10bfffff]
[    1.966758] 1 fixed-partitions partitions found on MTD device 10800000.flash
[    1.976141] Creating 1 MTD partitions on "10800000.flash":
[    1.984261] 0x000000000000-0x000000400000 : "rootfs"
[    2.243707] 40070000.serial: ttyAMA0 at MMIO 0x40070000 (irq = 33, base_baud = 0) is a SBSA
[    2.255795] printk: console [ttyAMA0] enabled
[    2.255795] printk: console [ttyAMA0] enabled
[    2.268760] printk: legacy bootconsole [pl11] disabled
[    2.268760] printk: legacy bootconsole [pl11] disabled
[    2.378510] 40078000.serial: ttyAMA1 at MMIO 0x40078000 (irq = 34, base_baud = 0) is a SBSA
[    2.430434] clk: Disabling unused clocks
[    2.431057] PM: genpd: Disabling unused power domains
[    2.472629] cramfs: checking physical address 0x10800000 for linear cramfs image
[    2.474352] cramfs: linear cramfs image on mtd:rootfs appears to be 1312 KB in size
[    2.478758] VFS: Mounted root (cramfs filesystem) readonly on device 31:0.
[    2.483692] devtmpfs: mounted
[    2.492050] Freeing unused kernel image (initmem) memory: 20K
[    2.494287] This architecture does not have kernel memory protection.
[    2.495122] Run /sbin/init as init process
~ # head -n 5 /proc/meminfo 
MemTotal:           6260 kB
MemFree:            3020 kB
MemAvailable:       2796 kB
Buffers:               0 kB
Cached:              536 kB
~ # 
```

# Raspberry Pi Pico 2 Buildroot XIP hacks

How to build:

```bash
git clone https://github.com/Mr-Bossman/pi-pico2-linux

cd pi-pico2-linux

git submodule update --init

# cd buildroot
# make BR2_EXTERNAL=$PWD/../ raspberrypi-pico2_defconfig
make -C buildroot BR2_EXTERNAL=$PWD/ raspberrypi-pico2_defconfig

make -C buildroot

# flash the bootloader
make -C psram-bootloader flash

# then reboot the board and enable bootsel again so it reloads the partition table

make -C psram-bootloader flash-kernel
```

This will flash the bootloader, the dtb, the xipImage and the rootfs (CRAMFS) to the correct partitions.

## Designed to work with [SparkFun Pro Micro - RP2350](https://www.sparkfun.com/products/24870)

![Image of boot](images/booting.png)

#### NOTES on SDK
This project uses the sdk and tools installed to `~/.pico-sdk/`.
To use the tools and sdk installed to another location see [this issue](https://github.com/raspberrypi/pico-sdk/pull/1820#issuecomment-2291611448)
or the following.

```bash
export PICO_SDK_PATH=~/example_sdk/sdk/2.0.0/
export PICO_TOOLCHAIN_PATH=~/example_sdk/toolchain/13_2_Rel1
export pioasm_DIR=~/example_sdk/tools/2.0.0/pioasm
export picotool_DIR=~/example_sdk/picotool/2.0.0/picotool

make flash-kernel
```

#### NOTES on Atomics
On page 307 of the RP2350 Datasheet MCAUSE register CODE 7 says:
> Store/AMO access fault. A store/AMO failed a PMP check, or
encountered a downstream bus error. Also set if an AMO is attempted on a
region that does not support atomics (on RP2350, anything but SRAM).

Atomics will only work in SRAM, the kernel is located PSRAM, not SRAM.
The `lr` and `sr` atomic load and store will always return error in this region causing most code using them to behave incorrectly.
Most implementations assume `lr` and `sr` will eventually succeed.

### Use on other boards

This only works on the RP2350 RISC-V cores.

If you want to run this on other boards, please change the `PICO_BOARD` variable in `CMakeLists.txt`.
`set(PICO_BOARD sparkfun_promicro_rp2350 CACHE STRING "Board type")`

You will also need to set the psram CS pin with the `SFE_RP2350_XIP_CSI_PIN` macro in `bootloader.c`.
As of now the only psram chip tested is the `APS6404L` and any others may not work.
