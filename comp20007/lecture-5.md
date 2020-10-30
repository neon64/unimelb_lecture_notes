# Lecture 5 - Recursive Algorithms (17/03/2020)

>  I need you to look at me and look puzzled, or maybe look engaged, or be sleeeepy. That makes me tick.
> 
> - Lars Kulik 2k20

## Matrix Multiplication

Numer of multiplications for a matrix of size <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> is

<p align="center"><img src="svgs/b8bfad8d0d1c01026aaa24c86ace4e6c.svg?invert_in_darkmode" align=middle width=153.60550919999997pt height=131.4769797pt/></p>

Why the three nested sums?

- for each cell in the output matrix we have to sum up a whole row / column worth of information.

## Recursive algorithms

```pseudocode
function F(n)
    if n = 0 then return 1
    else return F(n-1) * n
end
```

<p align="center"><img src="svgs/2895ec6e1fcb433428bb64f8f81822fc.svg?invert_in_darkmode" align=middle width=298.84671134999996pt height=16.438356pt/></p>

Solving this recurrence relation using telescoping and backwards substitution.

<p align="center"><img src="svgs/55f8f25a42e406968c78aa75484e3226.svg?invert_in_darkmode" align=middle width=546.13656735pt height=16.438356pt/></p>

When <img src="svgs/9c816cbee3cb469f335eb5a003df1e6c.svg?invert_in_darkmode" align=middle width=40.85987564999999pt height=22.831056599999986pt/>, we get to case <img src="svgs/da7b64fa16c2c0112ec085b0609b66db.svg?invert_in_darkmode" align=middle width=38.74435784999999pt height=24.65753399999998pt/>.

<p align="center"><img src="svgs/eae7596bbad681faf9209964e178fe93.svg?invert_in_darkmode" align=middle width=302.09251875pt height=16.438356pt/></p>

So its linear.

### Binary search

<p align="center"><img src="svgs/239b5eb5b13b7adcadb8530cada410a1.svg?invert_in_darkmode" align=middle width=272.52949514999995pt height=16.438356pt/></p>

In the base case, we're not doing any comparison - thus <img src="svgs/29632a9bf827ce0200454dd32fc3be82.svg?invert_in_darkmode" align=middle width=8.219209349999991pt height=21.18721440000001pt/> work.

A *smoothness* rule allows us to assume that <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> is a power of 2.

- e.g. happily assume that <img src="svgs/00d1639b279f29d70e6bc7f4978c1698.svg?invert_in_darkmode" align=middle width=46.55626304999999pt height=26.76175259999998pt/>

<p align="center"><img src="svgs/f2fc701d65498473a8ae0f5bc89009b5.svg?invert_in_darkmode" align=middle width=154.25876399999999pt height=16.438356pt/></p>

<p align="center"><img src="svgs/f6da78d00064c7a5d9b31e0a4ecbf69b.svg?invert_in_darkmode" align=middle width=215.62423574999997pt height=90.41095965pt/></p>

<p align="center"><img src="svgs/92debbaf8a3f675b9920e696550910f2.svg?invert_in_darkmode" align=middle width=247.69247414999998pt height=150.01677734999998pt/></p>

We can just write <img src="svgs/0695cb495234f0b44f29ae7e3a799408.svg?invert_in_darkmode" align=middle width=21.232944149999987pt height=22.831056599999986pt/> for any logarithmic function - only changed by some constant factor.

<p align="center"><img src="svgs/48a6a23fe4689378a448cebc8057f14f.svg?invert_in_darkmode" align=middle width=354.51431069999995pt height=16.438356pt/></p>

#### Reasoning with Big-Oh

- performing one operation after the other:

<p align="center"><img src="svgs/30acf4119bbbf532b19adb9065de322c.svg?invert_in_darkmode" align=middle width=292.67201865pt height=16.438356pt/></p>

- constants can be thrown away:

<p align="center"><img src="svgs/eef0f3e05db2e6ddfc3f8f61c558a6c4.svg?invert_in_darkmode" align=middle width=157.4045781pt height=16.438356pt/></p>

- this one is very useful for lots of nested loops:  (e.g.: matrix multiplication)

<p align="center"><img src="svgs/a08613f578fa778625535795fe395ca8.svg?invert_in_darkmode" align=middle width=250.10894864999997pt height=16.438356pt/></p>

- Stirling's algorithm for simplifying factorials:

<p align="center"><img src="svgs/ebdbf582eb6abdefead2ab0f0003abc0.svg?invert_in_darkmode" align=middle width=100.57666409999999pt height=20.611176299999997pt/></p>
