# What's a rail fence cipher?

A railfence cipher it's a really simple and rudimentary method of criptography.
It's usually written with the assistance of a matrix, but thats not necessary!

*This repository contains a C code that shows how to encrypt a message through the Rail Fence method without relying on matrixes.*

## How the Rail Fence method works:

First we choose a message, preferably without spaces: 

>*HelloWorld* 

Then, we choose our key, let's say 
>4

The next step is to create a matrix m x n, which m is the key, and n is the length of the message.

In this matrix we gonna dispose our message following the diagonals back and forth, like this:
```
|H| | | | | |O| | | |
| |E| | | |W| |R| | |
| | |L| |O| | | |L| |
| | | |L| | | | | |D|
```
The last step is to read all the lines from the top to the bottom, from the left to the right.

The encrypted message then will be: **HOEWRLOLLD**

## The Problem:

As we can see, using a matrix is very intuitive and makes the process very easy.

But it's not practical from a computer standpoint.

We have a lot of empty spaces, and the bigger the message is the worse this waste of memory gets.

# Encrypting without a matrix:

We can look at this encryption method as a variable **i** that contains a position of a character in the message **string**.

*Note that now we're dealing with one dimensional arrays*

This position starts at 0, which is 'H' and jumps 6 positions for the 6, (because we have a gap of 5 spaces between) which is the second 'O'.

Then it could jump again, but it would exceed the lenght of the messsage, when that happens it's time to start again from position 1, which is the second letter in the array and the third letter in the encrypted message.

The problem now is that the jumps have different lengths, and the algorithm has to take that into consideration.

It's not hard to see that the first gap, or the first jump, can be calculated by:

> (key - 1) * 2

Now that we have the information of the first gap, we can calculate the information about the other gaps and store it in an array. 

The array will be completed like this:
```
key = 4
q = (key - 1)*2;
m = 0;
int i = 0;

while (i < key) {
  k[i] = q - m;
  m = m + 2;
  i++;
} k[key - 1] = 0

k : {6, 4, 2, 0}
```

*Observe that k has all the jumps that will be done in the encryption process.
All we have to do is use this information correctly.*

Using two variables **l** and **n**, that will take values from 0 to 3, indexes for the k array, we can keep track of which gaps we are in, and thus the jumps we should do next.
We can switch between each variable using a simple % 2 operation with a counting variable.

**l** starts from zero and always moves forward in k.

**n** starts from key - 1 and always moves backwards in k.

After exceeding the message length, **i** starts from the next "ordinal letter", and the process of jumping is done again, a total of **key** times.

*Ordinal letter is the first letter of each line in the Rail Fence matrix*

With this set up, we have created a condition that informs **i** which jump it should do next, and thus, which position our next letter is, completing the encryption without a matrix.
