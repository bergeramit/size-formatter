# size-formatter

Easy way to tranfer between sizes.
curretly runs out of the box with linux. 

## Usage

```
make install
sf -h
```

### Example Commands

Command     | Output
----------- | ----------
`sf -h`     | Shows Usage
`sf 0x3a`   | Shows all formats for 58 bytes
`sf 80MiB`  | Shows all formats for 80 * (2 ** 20) bytes
`sf 23`     | Shows all formats for 23 bytes
`sf 33B`    | Shows all formats for 33 Bits
`sf 76Mb`   | Shows all formats for 76 * ((10 ** 6) / 8) bytes
`sf 83MB`   | Shows all formats for 83 * ((10 ** 6)) bytes

### Example run
#### Input
`sf 0x3a`

#### Output
```
-- ALL FORMATS --
->   0.000058 MB
->   0.000464 Mb
->   0.000055 MiB
->   0.058000 KB
->   0.464000 Kb
->   0.056641 KiB
->   58.000000 b
->   464.000000 B
```

# version release - 1.0
## Features
1. Supports Convert Table below
2. full linux support with make install

## To-Do
1. Add windows support in compilation
2. make better usage

## Convert Table
convert the input -> bytes

Sign        | Convert Value
----------- | ---------------
MB          | 10 ** 6
Mb          | (10 ** 6) / 8
MiB         | 2 ** 20
KB          | 10 ** 3
Kb          | (10 ** 3) / 8
KiB         | 2 ** 10
b           | 1
B           | 1 / 8
