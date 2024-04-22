# Homework

## env setup

# libc

## Formatted input: `scanf`, `fscanf`

- `fscanf` read from file stream

- ```
  int fscanf(FILE *stream, const char *format, ...)
  ```

- Be careful for error handeling. (**RETURN VALUE**)

- **Returns** the number of input items successfully matched and assigned.

## Formatted output: `printf`, `fprintf`, `sprintf`, `snprintf`

**Write formatted data to ...**

- `fprintf`

- ```
  int fprintf(FILE *stream, const char *format, ...)
  ```

- **Return** the total number of characters written otherwise, a negative number is returned.

- `sprintf`

- ```
  int sprintf(char *str, const char *format, ...)
  ```

- **Return** the total number of characters written otherwise, a negative number is returned.

- `snprintf`

- ```
  int snprintf(char *buffer, size_t n, const char *format-string,argument-list);
  ```

- **Return Value**: The `snprintf()` function returns the number of bytes that are written in the array, not counting the ending null character. If an encoding error occurs, a negative number is returned.

Difference between `sprintf` and `snprintf`

**Buffer Overflow Protection**:

- `sprintf`: No protection against buffer overflow.
- `snprintf`: Protects against buffer overflow by truncating the output if it exceeds the specified size.

## Convert the string back to a float

- ```
  double atof(const char *str)
  ```

- **Return** the converted float number If no valid conversion could be performed, it returns zero (0.0).

## `memset`

- ```
  void *memset(void *ptr, int c, size_t n)
  ```
  
- Sets the first *num* bytes of the block of memory pointed by *ptr* to the specified *value*.

## Copy: `strcpy`, `memcpy`

- ```
  char * strcpy ( char * destination, const char * source );
  ```

- ```
  void* memcpy( void* dest, const void* src, std::size_t num );
  ```

## Compare: `strcmp`, `memcmp`.

- ```
  int strcmp (const char* str1, const char* str2);
  ```

- **Return** value >0 if the first non-matching character in str1 is greater (in ASCII) than that of str2.

- ```
  int memcmp ( const void * ptr1, const void * ptr2, size_t num );
  ```

- **Return** value >0 if the first byte in memory blocks has a greater value in *ptr1* than in *ptr2* (if evaluated as *unsigned char* values)

- `memcmp` needs a length, while string are `\0` terminated.

## Move: `memmove`

- ```
  void * memmove ( void * destination, const void * source, size_t num );
  ```

- *destination* is returned.