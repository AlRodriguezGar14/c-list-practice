Sort algorithm. Brainstorming:

LSD sort; from the least significant bit to the most (max_bits - 1)
Explaination of how this sorting is possible:
https://www.youtube.com/watch?v=Uey0-GOMtT8
How bit imeplementation works:
https://www.youtube.com/watch?v=dPwAA7j-8o4
https://www.youtube.com/watch?v=y52JkxUTg-o
https://www.youtube.com/watch?v=iS0S7F2U4-o

more information:
https://www.cs.princeton.edu/courses/archive/spr02/cs226/lectures/radix.4up.pdf



// Understanding the logic behind Radix algorithm:
// Let's say we have the numbers 1, 2, 3, and 4 to sort, and we'll represent them in binary:

// 1 in binary is 0001
// 2 in binary is 0010
// 3 in binary is 0011
// 4 in binary is 0100
// Now, we'll sort these numbers using the radix sort algorithm:

// First pass (least significant bit): We look at the rightmost bit (least significant bit) of each number. If the bit is 1, we move the number to the end of the line. If the bit is 0, we move the number to a different line. After this pass, our numbers are arranged as follows:

// Line A: 2 (0010), 4 (0100)

// Line B: 1 (0001), 3 (0011)

// Second pass (second bit): We now look at the second bit from the right. Again, if the bit is 1, we move the number to the end of the line. If the bit is 0, we move the number to a different line. After this pass, our numbers are arranged as follows:

// Line A: 1 (0001)

// Line B: 2 (0010), 4 (0100), 3 (0011)

// Third pass (third bit): We now look at the third bit from the right. After this pass, our numbers are arranged as follows:

// Line A: 1 (0001), 2 (0010)

// Line B: 4 (0100), 3 (0011)

// Fourth pass (most significant bit): We now look at the leftmost bit (most significant bit). After this pass, our numbers are arranged as follows:

// Line A: 1 (0001), 2 (0010), 3 (0011)

// Line B: 4 (0100)

// At the end of these four passes, our numbers are sorted in ascending order: 1, 2, 3, 4. This is how the radix sort algorithm works. It systematically sorts numbers bit by bit, starting from the least significant bit and moving to the most significant bit.