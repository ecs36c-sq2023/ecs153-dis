# Midterm

- Length: 1hour
- Open book.
- No electronic devices.
- One answer sheet and one exam booklet.
- Write name on both answer sheet and booklet.

# security principles

## 1. know your threat model

- Who your attacker is.
- What kinds of resources they have.
- Assumptions can be made with above info.
- For old code, the threat model may change.

## 2. consider human factors

Security system: Simple, intuitive and easy to use.

## 3. Security is economics

- Systems only need to be protected against a certain level of attacks.
- Wooden barrel effect: Focus on securing the weakest links. Security is like a chain: a system is only as secure as the weakest link.
- balance conservative design and “security is economics”

## 4. Detect if you can’t prevent

- prevention is stopping an attack from taking place
- detection is simply learning that the attack has taken place, and response would be doing something about the attack.

## 5. Defense in depth

Multiple types of defenses should be layered together so an attacker would have to breach all the defenses to successfully attack a system.

## 6. Least privilege

Privilege isolation

Give a program the set of access privileges that it legitimately needs to do its job—but nothing more. Try to minimize how much privilege you give each program and system component.

## 7. Separation of responsibility

Split up privilege, so no one person or program has complete power. Require more than one party to approve before access is granted.

## 8. Ensure complete mediation

When executing access control policies, make sure that you check *every* access to *every* object. This kind of thinking is helpful to detect where vulnerabilities could be. As such, you have to ensure that all access is monitored and protected.

## 9. Shannon’s Maxim

Shannon’s Maxim states that the attacker knows the system that they are attacking.

Never rely on obscurity as part of your security. Always assume that the attacker knows every detail about the system that you are working with (including its algorithms, hardware, defenses, etc.)

## 10. Use fail-safe defaults

Choose default settings that “fail safe”, balancing security with usability when a system goes down.

## 11. Design security in from the start

It's difficult to redesign security on an exisiting application.

## 12. The Trusted Computing Base (TCB)

**TCB Design Principles**:

- *Unbypassable (or completeness):* There must be no way to breach system security by bypassing the TCB.
- *Tamper-resistant (or security):* The TCB should be protected from tampering by anyone else. For instance, other parts of the system outside the TCB should not be able to modify the TCB’s code or state. The integrity of the TCB must be maintained.
- *Verifiable (or correctness):* It should be possible to verify the correctness of the TCB. This usually means that the TCB should be as simple as possible, as generally it is beyond the state of the art to verify the correctness of subsystems with any appreciable degree of complexity.

# Memory safety

## 1. Compiler, Assembler, Linker, Loader (CALL)

Four main steps to running a C program.

1. The *compiler* translates your C code into assembly instructions.
2. The *assembler* translates the assembly instructions from the compiler into machine code (raw bits).
3. The *linker* resolves dependencies on external libraries. After the linker is finished linking external libraries, it outputs a binary executable of the program that you can run.
4. When the user runs the executable, the *loader* sets up an address space in memory and runs the machine code instructions in the executable.

## 2. Little-endian

The least significant byte is stored at the lowest address, and the most significant byte is stored at the highest address.

## 3. C memory layout

- The *code* section contains the executable instructions of the program.
- The *static* section contains constants and static variables that never change during program execution, and are usually allocated when the program is started.
- The *heap* stores dynamically allocated data. When you call `malloc` in C, memory is allocated on the heap and given to you for use until you call `free`. The heap starts at lower addresses and “grows up” to higher addresses as more memory is allocated.
- The *stack* stores local variables and other information associated with function calls. The stack starts at higher addresses and “grows down” as more functions are called.

## Registers

- eip

- ebp
- esp

## x86 function calls

## Buffer overflow vulnerabilities

out-of-bounds memory access that writes beyond the bounds of some memory region.

## Stack smashing

<img src="https://textbook.cs161.org/assets/images/memory-safety/vulnerabilities/overflow4.png" alt="Two words of memory for buf overwritten and the rip and sfp above it overwritten" style="zoom:50%;" />

If the input is too long, the code will write past the end of `buf`, overwrite the sfp, and overwrite the rip. This is a *stack smashing* attack.

Note that even though we are on the stack, which “grows down,” our input writes from lower addresses to higher addresses. The stack only grows down when we call a new function and need to allocate additional memory. When we call `gets`, user input is still written from lower addresses to higher addresses, just like before.

## Format string vulnerabilities

```c
char* user_input = "Hello World";
printf(user_input);
```

As long as `user_input` is guaranteed to contain no format specifiers, this is fine. 

But if that value is controlled by the user, an attacker can exploit format string syntax to trigger a variety of dangerous behaviors.

```c
printf("%x%x%x%x");
```

For each format specifier it encounters in the format string, `printf()` expects to find a suitable variable in its argument list. It just looks at the stack and reads the first variable after the format string. 

This is repeated for all four `%x` specifiers, so the example above will print the hex representation of four values from the stack.

##  Integer conversion vulnerabilities

```c
typedef unsigned int size_t;
void *memcpy(void *dest, const void *src, size_t n);
```

If executed with a negative argument n.

C will cast this negative value to an `unsigned int` and it will become a very large positive integer. Thus `memcpy()` will copy a huge amount of memory into `buf`, overflowing the buffer.

## Off-by-one vulnerabilities

**occurs when a buffer operation is executed once more than it should**

![img](https://csl.com.co/wp-content/uploads/2016/03/1_CODIGO.png)

The buf array length is defined as 128.

Line 8 is defined from 0 to 128, not to 127.

Should execute 128 times, but actually execute 129 times.

# Mitigating Memory-Safety Vulnerabilities

## Use a memory-safe language

Java, Python, Go, Rust, Swift

## Writing memory-safe code

## Building secure software

## Exploit mitigations

## Mitigation: Non-executable pages

Modern systems separate memory into *pages* in order to support virtual memory.

Each page of memory is set to either be writable or executable.

If attacker wrote machine code to a page in memory, that page cannot be executed as machine instructions, so the attack no longer works.

## Subverting non-executable pages: Return into libc

## Subverting non-executable pages: Return-oriented programming

## Mitigation: Stack canaries

Stack canary is a sacrifical value: If it is changed, it shows a warning that someone may be trying to exploit our program.

**Detect if you can not prevent.**

## Mitigation: Pointer authentication

## Mitigation: Address Space Layout Randomization (ASLR)

## Subverting ASLR

# Cryptography

## Confidentiality, Integrity, Authenticity

*Confidentiality* attackers can not read the data.

*Integrity*: attackers can not edit the data

*Authenticity*: able to know who created a given message.

# Symmetric-Key Encryption

- IND-CPA Security
- XOR review
- One Time Pad
- Block Ciphers
- Block Cipher Security
- Block Cipher Modes of Operation
- Cryptographic Hashes

## Properties of Hash Functions

- **One-way** 
- **Second preimage resistant**
- **Collision resistant** 

# Message Authentication Codes (MACs)

A MAC is a keyed checksum of the message that is sent along with the message. It takes in a fixed-length secret key and an arbitrary-length message, and outputs a fixed-length checksum. A secure MAC has the property that any change to the message will render the checksum invalid.

- Integrity and Authenticity
- Difference between a MAC and a digital signature
  - A MAC uses a symmetric key
  - digital signature uses an asymmetric key pair
  - MAC algorithms are typically faster and more efficient than digital signature algorithms, but they do not provide non-repudiation.