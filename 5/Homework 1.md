# Homework 1

## due

## Fixed-percision integers

```
int64_t
uint32_t
```

- Representation may incorrect when numbers were larger or smaller than the limit.

## Arbitrary precision int APInt

Example:

```c
typedef struct APInt {
  int size;
  uint8_t *bytes;
} APInt;
```

## Input specification

```
2
UINT64
1
UINT64
2
POW
1 1 65536
DUMP
POW
0 0 18446744073709551615
END
```

The following `2n` lines describes these `n` `APInt`s. First line would be one of the following three: `UINT64`, `HEX_STRING`, `CLONE`.

- `UINT64`, the following line will be an integer with type `uint64_t`. It's guaranteed that the integer is valid.
- `HEX_STRING`, the following line will be a string that satisfies [regular expression](https://en.wikipedia.org/wiki/Regular_expression): `[0-9,a-f]*`. Simply put, it is a number represented using hexadecimal. It may be very large. This string also guarantees to be valid.
- `CLONE`, followed by an index. This number of be a clone of a previous integer. The index guarantees to be valid.
- Any other inputs should be considered illegal and the program should terminate immediately.

## Commands

- `DUMP`, `DUMP` has no arguments. It will print the `APInt`s one by one. Each `APInt` should be printed with a leading `0x`, then it's hexadecimal representation. If the number takes odd number of digits, a zero should be padded before it. (e.g. `0x01` instead of `0x1`) Each `APInt` should take ONE line, and an extra line should be printed at the end.

- `END` indicates that this is the final command, the program should quit now.

- Left shift: `SHL` has three operands in the next line: `dst`, `src`, `k`, seperated by a space. You should take `src`-th `APInt` in the array, left shift it by `k` **bits**, and store it back to `dst`-th place in the array. `k` is `uint64_t`.

  - 1 byte = 8 bits

- `ADD` has three operands in the next line: `dst`, `op1`, `op2`, seperated by a space. All three operands are indices. You should take `op1` and `op2` from the array, add them and place the result back to `dst`.

- `MUL_UINT64` has three operands in the next line: `dst`, `src`, `k`, seperated by a space. You should calculate `src * k`, and store it back to `dst`-th place in the array. `k` is `uint64_t`.

- `MUL_APINT` has three operands in the next line: `dst`, `op1`, `op2`, seperated by a space. All three operands are indices. You should take `op1` and `op2` from the array, multiply them and place the result back to `dst`.

- `POW`has three operands in the next line:`dst`, `src`, `k`, seperated by a space. You should take

  `src`-th `APInt` in the array, calculate `src ^ k`, and store it back to `dst`-th place in the array.

  `k` is `uint64_t`.

  - Hint: This task has performance requirements. `O(k)` solution is intuitive, can you think of an `O(log k)` one?

- `CMP` has two operands in the next line: `op1`, `op2`, seperated by a space. Both operands are indices. You should take `op1` and `op2` from the array, compare them. Print -1 if `op1` is less than `op1`, 0 if equal, 1 if greater.

- Any other inputs should be considered illegal and the program should terminate immediately.

