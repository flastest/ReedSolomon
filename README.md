# Reed Solomon
### Ariel Flaster 
#### CSCI 421


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
at all different than what I learned a 'ring' was in other math classes. Mathematicians just want to watch everyone else suffer through their 
senseless naming schemes I guess. Our Galois field is for the number eight. Basically, you can multiply or add any numbers from zero 
through seven, and then you just need to modulo eight at the end to ensure it stays in the field. 

This is used in Reed Solomon because all the polynomials are in a Galois field.

### Matrix multiplication

To decode, we use matrix multiplication to multiply our chunk by another matrix. Lets call our encoding matrix 'E' and our original 
data matrix 'A'.  We multiply E by A to get our Reed Solomonized chunk of data, which I'll call R. E is invertible, so E * E<sup>-1</sup> = I. 
Given EA = R, we also have A = R * E<sup>-1</sup>. So we can use R and E<sup>-1</sup> to reconstruct A.


## 'My' 'Implementation'

I borrow code from Henry Minsky who licensed this under the GNU General Public License. I totally lost it while trying to make this, but at least I
can try to explain this open source Reed-Solomon implementation. I am dying inside. I DON'T CLAIM TO HAVE WRITTEN THIS CODE! I am on the verge of
a catastrophic mental breakdown so I just want to get some credit for explaining someone else's implentation since I can't write my own.

I made experiment.cc in the likeness of Henry Minsky's example.c, where the only difference is that experiment will flip random bits to emulate
what actually happens in a computer when we need to use Reed Solomon. 

Henry's encode_data function in rs.c takes a msg to be encoded, the number of bytes in msg, and a dst location for the encoded data to go. We need to
do synthetic polynomial division within the Galois field (hence the gmult) to get pBytes, the parity bytes that are used to encode in the build_codeword
function. Then we build the codeword, and we're done encoding!! 🎉🎉🎉 This is the best I've felt all day.

Decoding is a lot harder though, it's like a 5 step function from what I recall in my reading. Let's see how Henry does it.



### References
Henry Minsky (hqm@alum.mit.edu) 1991-2009

https://courses.cs.duke.edu//spring10/cps296.3/rs_scribe.pdf

https://en.wikiversity.org/wiki/Reed%E2%80%93Solomon_codes_for_coders

https://github.com/Backblaze/JavaReedSolomon

https://www.backblaze.com/blog/reed-solomon/


