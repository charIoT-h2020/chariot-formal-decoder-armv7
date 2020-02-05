CharIoT formal decoder armv7
============================

The formal decoder armv7 decodes binary instructions from a chunk of bytes
and it provides the formal side-effects of every instruction on the memory.

A demonstrator is available in the [armsec](armsec) directory.

An API will be made available in the [src](src) directory.

The API should contain two functions `armsec_next_targets` and
`armsec_interpret`. Both functions take:

* a chunk of bytes to decode,
* an abstract memory model and callback functions for load/store
  and register accesses,
* an abstract arithmetic & logic model and callback functions for
  computations

# build armsec

You first need to go in the `armsec` directory.
Then the standard commands should build the executable `unisim-armsec-1.0.9`.

```sh
mkdir build_release
cd build_release
../configure --prefix=$PWD
make
# make -j 8
```

# build armsec\_decoder.so

`armsec` should have been previously built to generate the files
`armsec/build_release/armsec/top_thumb.hh` and
`armsec/build_release/armsec/top_thumb.cc`.

You need to go in the `src` directory. Then you need to create a
sub-directory `armsec` that contains the previously generated files:

```sh
mkdir -p armsec
ln -s ../armsec/build_release/armsec/top_thumb.hh armsec/top_thumb.hh
ln -s ../armsec/build_release/armsec/top_thumb.cc armsec/top_thumb.cc
```

Then the command

```sh
make
```

creates the dynamic library `armsec_decoder.so` whose API is
`armsec_decoder.h`. The test `check_memory` uses this API as
a proof of concept for propagating a memory model over arm
instructions.

# demo of armsec

You can use the armv7 `objdump` utility to compare the mnemonic of the
instructions.

```sh
arm-none-eabi-objdump -D -b binary -marm -Mforce-thumb modbus.nobug.bin | less
```

In this example, at the address `0x170a`, `objdump` gives
the mnemonic

```
170a:       b538            push    {r3, r4, r5, lr}
```

`armsec` gives the same mnemonic by providing the address and a chunk of bytes
that starts with the instruction: ex `0xb538`, or  `0x4604b538`.

```sh
.../armsec/build_release/armsec/unisim-armsec-1.0.9 thumb 0x170a 0xb538
.../armsec/build_release/armsec/unisim-armsec-1.0.9 thumb 0x170a 0x4604b538
```

It also generate a local control flow graph to semantically interpret the
instruction

```
(0x0000170a,0) tmp32_0<32> := (sp<32> + 0xfffffff0); goto 1
(0x0000170a,1) tmp8_0<8> := ((itstate<8> and 0xe0) or ((itstate<8> lshift 0x01) and 0x1f)); goto 2
(0x0000170a,2) if (((((((((((((((((itstate<8> and 0x0f) = 0x00) or (((itstate<8> rshiftu 0x04) = 0x00) and z<1>)) or (((itstate<8> rshiftu 0x04) = 0x01) and (not  z<1>))) or (((itstate<8> rshiftu 0x04) = 0x02) and c<1>)) or (((itstate<8> rshiftu 0x04) = 0x03) and (not  c<1>))) or (((itstate<8> rshiftu 0x04) = 0x04) and n<1>)) or (((itstate<8> rshiftu 0x04) = 0x05) and (not  n<1>))) or (((itstate<8> rshiftu 0x04) = 0x06) and v<1>)) or (((itstate<8> rshiftu 0x04) = 0x07) and (not  v<1>))) or (((itstate<8> rshiftu 0x04) = 0x08) and (not  ((not  c<1>) or z<1>)))) or (((itstate<8> rshiftu 0x04) = 0x09) and ((not  c<1>) or z<1>))) or (((itstate<8> rshiftu 0x04) = 0x0a) and (not  (n<1> xor v<1>)))) or (((itstate<8> rshiftu 0x04) = 0x0b) and (n<1> xor v<1>))) or (((itstate<8> rshiftu 0x04) = 0x0c) and (not  (z<1> or (n<1> xor v<1>))))) or (((itstate<8> rshiftu 0x04) = 0x0d) and (z<1> or (n<1> xor v<1>)))) or ((itstate<8> rshiftu 0x04) = 0x0e))  goto 4 else goto 5
(0x0000170a,3) goto (0x0000170c,0)
(0x0000170a,4) @[tmp32_0<32>,<-,4] := r3<32>; goto 6
(0x0000170a,5) if ((itstate<8> and 0x0f) <> 0x00)  goto 14 else goto 3
(0x0000170a,6) @[(sp<32> + 0xfffffff4),<-,4] := r4<32>; goto 7
(0x0000170a,7) @[(sp<32> + 0xfffffff8),<-,4] := r5<32>; goto 8
(0x0000170a,8) @[(sp<32> + 0xfffffffc),<-,4] := lr<32>; goto 9
(0x0000170a,9) if ((itstate<8> and 0x0f) <> 0x00)  goto 11 else goto 10
(0x0000170a,10) sp<32> := tmp32_0<32>; goto 3
(0x0000170a,11) if ((itstate<8> and 0x07) <> 0x00)  goto 12 else goto 13
(0x0000170a,12) itstate<8> := tmp8_0<8>; goto 10
(0x0000170a,13) itstate<8> := 0x00; goto 10
(0x0000170a,14) if ((itstate<8> and 0x07) <> 0x00)  goto 15 else goto 16
(0x0000170a,15) itstate<8> := tmp8_0<8>; goto 3
(0x0000170a,16) itstate<8> := 0x00; goto 3
```

For a branch and link instruction, `armsec` also use the address to give the
mnemonic.

```sh
.../armsec/build_release/armsec/unisim-armsec-1.0.9 thumb 0x1710 0xf822f000
```

# demo of the API

The command

```sh
./check_memory -dom .../libScalarInterface.so .../modbus.nobug.bin 170a memory.json
```

should load the registers and interpret the binary instructions of the linear
bloc, starting at offset `170a`.

