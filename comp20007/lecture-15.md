# Lecture 15 - Hash Tables

Implementation of the *dictionary* abstract data structure.
<p align="center"><img src="svgs/1427a57977c612f5180cc6e5f6b2c07f.svg?invert_in_darkmode" align=middle width=275.61718635pt height=16.438356pt/></p>

- continuous data structure, <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/> preallocated entries

difficulties:

- need to preallocate a lot of memory
- hash collisions

## Hash function:

<p align="center"><img src="svgs/3d17259109ae491cbcde8728afff166e.svg?invert_in_darkmode" align=middle width=156.1195548pt height=16.438356pt/></p>

- should be efficient (<img src="svgs/8baa6519095a4bdbc7392b4a8b5116dc.svg?invert_in_darkmode" align=middle width=33.79007609999999pt height=24.65753399999998pt/>)

- distributes keys evenly along the table

#### Identity hash function

- <img src="svgs/6689ef9f2eac5c7b2cbfb5505dfcbe3f.svg?invert_in_darkmode" align=middle width=74.44818479999998pt height=24.65753399999998pt/>
- But need to know the maximum number of keys in advance, since <img src="svgs/075c11ae23ffbd1f103289dad1940c92.svg?invert_in_darkmode" align=middle width=102.62917994999998pt height=24.65753399999998pt/>
- e.g.: Australian postcodes, 0-9999
- however often fails
  - <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/> is too large
  - unbounded integers (student IDs)
  - non-integer keys

#### Hashing integers

- <img src="svgs/74d880af679e6b72b8a26b542ef80604.svg?invert_in_darkmode" align=middle width=131.34712469999997pt height=24.65753399999998pt/>
- can set the size <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/>
- small <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/> - lots of collisions, large <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/> - too much memory

#### Hashing strings

- assume A -> 0, B -> 1
- Assume 26 characters and m=101
- Each character can be mapped to a binary string of length 5 (2^5 = 32)
- e.g.:
  - 13379736 mod 101 = 64
- <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/> deliberately chosen to be prime
- otherwise if <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/> is 32, then the hash value of any key is the last character's string (since each letter is 32 bits)

<p align="center"><img src="svgs/a9cfc715af4a7cac1916f4fad3172ca2.svg?invert_in_darkmode" align=middle width=292.00183649999997pt height=49.9887465pt/></p>

- will quickly result in overflow

**Horner's rule - factor out things and take mod**

- can use properties of modular arithmetic

## Separate Chaining

- each entry is a pointer to a linked list
- needs even more memory

**load factor: <img src="svgs/fae8fadb0f6075554671423ae666584b.svg?invert_in_darkmode" align=middle width=65.01331484999999pt height=24.65753399999998pt/>**

- even distribution of <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> keys

- successful search requires 1 + <img src="svgs/ff3bce6882cadff6c470d18c0f8cb1ba.svg?invert_in_darkmode" align=middle width=27.01491704999999pt height=24.65753399999998pt/> operations on average
  
  - <img src="svgs/931e83ae3d7faedb0149097ea96b18ae.svg?invert_in_darkmode" align=middle width=120.54771794999998pt height=24.65753399999998pt/> - roughly O(1)
  - <img src="svgs/1e7fd600eb980724482b8b383177d73b.svg?invert_in_darkmode" align=middle width=93.68111939999999pt height=21.18721440000001pt/>

- successful search requires <img src="svgs/c745b9b57c145ec5577b82542b2df546.svg?invert_in_darkmode" align=middle width=10.57650494999999pt height=14.15524440000002pt/> operations on average

- similar numbers for Insert and Delete

- Worst case <img src="svgs/272e3ab168729ac17efd78e4c03be40f.svg?invert_in_darkmode" align=middle width=35.43774299999999pt height=24.65753399999998pt/> only with a really bad hash function (e.g.: map everything to first bucket) - load factor is a more practical consideration

## Linear Probing

- deletion is very complicated
  
  - most implementations leave some 'deleted' flag

- more widely used than separate chaining

- much harder analysis

- simplified results show:
  
  - successsful search <img src="svgs/483b24aaf1c8a284716f8fde29ab96c8.svg?invert_in_darkmode" align=middle width=99.02980889999999pt height=27.77565449999998pt/>
    - only makes sense if $\alpha < 1$
  - unsuccesful search <img src="svgs/9946d8423cdbecd61973562d1e282bd4.svg?invert_in_darkmode" align=middle width=115.71944504999998pt height=27.77565449999998pt/>

- deletion virtually impossibled

Worst case <img src="svgs/272e3ab168729ac17efd78e4c03be40f.svg?invert_in_darkmode" align=middle width=35.43774299999999pt height=24.65753399999998pt/> with a bad hash function and/or clusters

## Double hashing

- first try: <img src="svgs/9add9eb2902fb2a1c7e8d41d800c7f95.svg?invert_in_darkmode" align=middle width=37.39354739999999pt height=24.65753399999998pt/>

- second try: <img src="svgs/d59b9afdedca3ab5fbcbe263d77b5366.svg?invert_in_darkmode" align=middle width=155.49066555pt height=24.65753399999998pt/>

- third try: <img src="svgs/ee800b5f41919478d9ac3b5d49e5d9bf.svg?invert_in_darkmode" align=middle width=163.7098749pt height=24.65753399999998pt/>
  
  - can see this is a generalisation of linear probing

- both linear probing and double hashing - open addressing methods

## Rehashing

high load factors deteriorate performance

- rehashing - insert all elements into a new one, approx double the size
- very expensive, but infrequent

## Hash Tables vs BSTs

Hash Tables ignore key ordering, unlike BSTs

e.g.: "give me all records with keys between 100 and 200" are easy in a BST

- well tuned hash table is typically better than a BST

## In practice

Python dictionaries

- open addressing using pseudo-random probing
  - secondary hash follows some random sequence
- Rehashing happens when <img src="svgs/17f238ce3aaf437516fc23e71842e7e5.svg?invert_in_darkmode" align=middle width=41.019273899999995pt height=27.77565449999998pt/>

C++ `unordered_map`

- uses chaining
- rehashing when <img src="svgs/fa6a87918e5ec2985c2f21e622c4b7ac.svg?invert_in_darkmode" align=middle width=40.713337499999994pt height=21.18721440000001pt/>