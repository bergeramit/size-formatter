# size-formatter

curretly runs out of the box with linux

## Usage

`make install`

### Examples

Command     | Output
----------- | ----------
`sf -h`     | Shows Usage
`sf 0x3a`   | Shows all formats for 0x3a bytes
`sf 0x3a`   | Shows all formats for 0c bytes
`sf 80MiB`  | Shows all formats for 80 * (2 ** 20) bytes
`sf 23`     | Shows all formats for 23 bytes
`sf 33B`    | Shows all formats for 33 Bits
`sf 76Mb`   | Shows all formats for 76 * ((10 ** 6) / 8) bytes
`sf 83MB`   | Shows all formats for 83 * ((10 ** 6)) bytes

# version release - 1.0
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
