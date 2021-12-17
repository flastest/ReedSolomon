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

Reed Solomon is an algorithm that 

### Parity Checks

### Galois Fields

Galois fields are just a set of integers that can be added, multiplied, divided, you name it, but are always modded by a certain number. This is not
at all different than what I learned a 'ring' was in other math classes. Mathematicians just want to watch everyone else suffer I guess. Our Galois
field is just a 'ring' for the number eight. Basically, you can do any operation on any number from zero through seven, and then you just need to 
modulo eight at the end.

### Matrix multiplication



### References
https://courses.cs.duke.edu//spring10/cps296.3/rs_scribe.pdf
https://en.wikiversity.org/wiki/Reed%E2%80%93Solomon_codes_for_coders
https://github.com/Backblaze/JavaReedSolomon


