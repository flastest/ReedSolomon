# Reed Solomon
### Ariel Flaster 
#### CSCI 421
David, my heart is broken and I just wanna graduate

## Errors in their natural habitat

Errors occur naturally when storing things. Regardless of the medium, whether it's a floppy disk or flash drive, bits can randomly be erased or 
flipped when in transit. Reed Solomon is a widely used algorithm to create a compact copy of this data that can be used to fix bits that have 
been erased or flipped to restore the data to what it looked like originally.


## Other ways of correcting errors

A simple way to notice and repair bit erasure is by having multiple copies of the same data. If we wanted to make sure that a storage device kept 
track of a file 100 percent perfectly with no flaws, we could have multiple copies of that file and compare them when reading the file. If we saw 
that one copy skipped a bit while the other copies had that bit, we could assume that that bit was erased, and we could repair it by looking at the
other copies of the file. 


## Reed Solomon

Reed Solomon is an algorithm that aims to correct errors, but without having to save copious amounts of additional data in the form of copies of a 
file on your storage device. In the end, data is split into a set amount of shards that mostly store original data, but some will contain parity 
shards that we use to check to make sure the data isn't corrupt.  I will refer to a complete collection of original data shards and their respective
parity shards as a chunk of data. 

This is what a potential chunk of encoded Reed Solomonized data might look like:

| data | data | data |
|--|--|--|
| data | data | data |
| data | data | data |
| parity | parity | parity |

### Encoding Matrix

The number of parity shards varies based on the number of shards they will do parity for. We generate a chunk of Reed Solomonized data by multiplying 
an encoding matrix by the data we with to encode. This encoding matrix consists of an identity matrix with additional parity check rows on the bottom.
This will produce what we are going to store; the actual data and the parity check shards afterwards. It is important to note that the number of parity 
check shards are smaller than the number of data shards we're storing. This ensures that we are efficitently saving space with our error correcting code.

### Galois Fields

Galois fields are just a set of integers that can be added, multiplied, divided, you name it, but are always modded by a certain number. This is not
at all different than what I learned a 'ring' was in other math classes. Mathematicians just want to watch everyone else suffer I guess. Our Galois
field is just a 'ring' for the number eight. Basically, you can do any operation on any number from zero through seven, and then you just need to 
modulo eight at the end. 

### Matrix multiplication

To encode and decode, we use matrix multiplication to multiply our chunk by another matrix. 


### References
https://courses.cs.duke.edu//spring10/cps296.3/rs_scribe.pdf
https://en.wikiversity.org/wiki/Reed%E2%80%93Solomon_codes_for_coders
https://github.com/Backblaze/JavaReedSolomon
https://www.backblaze.com/blog/reed-solomon/


