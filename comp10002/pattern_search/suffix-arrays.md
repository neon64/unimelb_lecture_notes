# Lecture 7.3: Suffix Arrays

[[back to pattern search]](./README.md)

Links:
- [Stanford Lecture Notes - on suffix arrays and Burrows-Wheeler Transform](https://web.stanford.edu/class/cs262/presentations/lecture5.pdf)

## Problem

What happens if <img src="svgs/2f118ee06d05f3c2d98361d9c30e38ce.svg?invert_in_darkmode" align=middle width=11.889314249999991pt height=22.465723500000017pt/> is fixed and large (<img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/> << <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>) and there are multiple independent patterns to be checked. Is there a way of precomputing an *index*?

## Meet suffix arrays

A *suffix array* <img src="svgs/354b5d308139aaa370ad3d0124500da4.svg?invert_in_darkmode" align=middle width=80.25498854999998pt height=24.65753399999998pt/> is an array of pointers S[i] such that <img src="svgs/731fb36bd8d7186023b1ba36056830ae.svg?invert_in_darkmode" align=middle width=30.40100249999999pt height=22.465723500000017pt/> lexicographically precedes <img src="svgs/ad2acb633e5fe8b23d00dd84208c22e0.svg?invert_in_darkmode" align=middle width=47.04492209999998pt height=22.465723500000017pt/>.

How to construct one?

1. add a new symbol, sentinel symbol which is smaller than any other symbol in the alphabet (in this case `!`)

2. take all possible suffixes (from length 1 to length of whole string)

3. sort the suffixes lexicographically (alphabetical order)

Ends up looking like this:

![](screenshot_2019-09-18_11-17-27_753886358.png)

To find an arbitrary pattern in this text, you can binary search the suffix array! Binary search, thus need <img src="svgs/7b85e54feb1e67c7e5a0c33fe3d1738b.svg?invert_in_darkmode" align=middle width=51.06374789999999pt height=24.65753399999998pt/> steps to search for the pattern. e.g.: if <img src="svgs/235e834e1163938d661cdc6ad899d9f6.svg?invert_in_darkmode" align=middle width=113.97660119999998pt height=21.18721440000001pt/> (a billion), it will take only thirty steps. THen you need only maximum <img src="svgs/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=14.15524440000002pt/> string comparisons.

Note: all we actually need to store is the numbers <img src="svgs/a6b8cbc27278fe617886e3639cb8f1c4.svg?invert_in_darkmode" align=middle width=25.82305769999999pt height=24.65753399999998pt/>, not each substring <img src="svgs/8358abd61954b67bce79fff9d08fba91.svg?invert_in_darkmode" align=middle width=40.383657599999985pt height=24.65753399999998pt/>.

- Total time is <img src="svgs/b39a56ca8b30a4842c0d21da65b3b2ba.svg?invert_in_darkmode" align=middle width=76.79306414999999pt height=24.65753399999998pt/> per search. That's very fast.

## Suffix array construction

- simple approach: use a <img src="svgs/ff514eba41c59f90c20d895e80719763.svg?invert_in_darkmode" align=middle width=72.2268393pt height=24.65753399999998pt/> comparison-based sorting algorithm with each comparison requiring as many as <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> steps, which is <img src="svgs/aa9870286704e5b13ffbef6fbdd552a2.svg?invert_in_darkmode" align=middle width=79.60129979999998pt height=26.76175259999998pt/> average case and <img src="svgs/90846c243bb784093adbb6d2d0b2b9d0.svg?invert_in_darkmode" align=middle width=43.02219404999999pt height=26.76175259999998pt/> worst case. Not good.

- With ternary quicksort:
  - partition on one character, at depth <img src="svgs/2103f85b8b1477f430fc407cad462224.svg?invert_in_darkmode" align=middle width=8.55596444999999pt height=22.831056599999986pt/> in the strings, then do **three** recursive calls
  - roughly improves the worst case from <img src="svgs/90846c243bb784093adbb6d2d0b2b9d0.svg?invert_in_darkmode" align=middle width=43.02219404999999pt height=26.76175259999998pt/> to <img src="svgs/3987120c67ed5a9162aa9841b531c3a9.svg?invert_in_darkmode" align=middle width=43.02219404999999pt height=26.76175259999998pt/>.

- Suffix array construction is an active area of algorithmic research - best methods are O(n) overall, but take a lot of space.

## Another example:

If the source <img src="svgs/2f118ee06d05f3c2d98361d9c30e38ce.svg?invert_in_darkmode" align=middle width=11.889314249999991pt height=22.465723500000017pt/> is large, but fixed, and you want to test with a whole bunch of smaller patterns (i.e.: <img src="svgs/43b3680f9c6d5dbf310c335cfb7d6805.svg?invert_in_darkmode" align=middle width=59.00304134999999pt height=17.723762100000005pt/>)

Generate an array of suffixes

```
                           012345
For example for the string banana

6 <img src="svgs/9829bd0da07ba8b180f7da586f374baa.svg?invert_in_darkmode" align=middle width=16.908363449999992pt height=21.18721440000001pt/>
4 na<img src="svgs/343a6cd8063e74ddd0e39d940c03415d.svg?invert_in_darkmode" align=middle width=35.46439379999999pt height=21.18721440000001pt/>
2 nana<img src="svgs/3051654607e3aa3e2154921f4926c517.svg?invert_in_darkmode" align=middle width=54.02042414999999pt height=21.18721440000001pt/>
0 banana<img src="svgs/9d94b01bd01248c039e74644602df4ce.svg?invert_in_darkmode" align=middle width=8.21920935pt height=39.45205439999997pt/>
5 a<img src="svgs/343a6cd8063e74ddd0e39d940c03415d.svg?invert_in_darkmode" align=middle width=35.46439379999999pt height=21.18721440000001pt/>
1 anana<img src="svgs/3e14c923c74d30546ef47f9b4eae8b61.svg?invert_in_darkmode" align=middle width=61.07522189999999pt height=22.831056599999986pt/>
4 na<img src="svgs/8bc48cd2c459494566ad62df59bc3028.svg?invert_in_darkmode" align=middle width=45.331270049999986pt height=21.18721440000001pt/>

then the suffix array will look like this:

i       0 1 2 3 4 5 6

A[i]    6 5 3 1 0 4 2

```

one can then perform a binary search from that suffix array...

e.g.: if we want to see if the pattern 'na' exists within our text.at

start at `i=3`... that suffix is `anana<img src="svgs/befd12986cc592921055ee2758244538.svg?invert_in_darkmode" align=middle width=624.47817795pt height=22.831056599999986pt/>`. That is also to close to the start. `i=5` then gives `na<img src="svgs/8c8584f81797496d549f1e85f844b566.svg?invert_in_darkmode" align=middle width=329.4098775pt height=24.7161288pt/>O(log(n))<img src="svgs/aca5ae54b51fd3b793160bfd473e0ea4.svg?invert_in_darkmode" align=middle width=170.31672404999998pt height=21.68300969999999pt/>m<img src="svgs/aea88820803ab69fdbf167986dbac370.svg?invert_in_darkmode" align=middle width=318.4938372pt height=45.84475500000001pt/>O(m \cdot log(n))<img src="svgs/c99968777e2dc06e478986f5cf93ff1f.svg?invert_in_darkmode" align=middle width=371.82746865pt height=45.84475499999998pt/>O(nlogn)<img src="svgs/f9066e8d574810c2c43265816b0da6f2.svg?invert_in_darkmode" align=middle width=261.97421414999997pt height=22.831056599999986pt/>n<img src="svgs/a9fa860881989feb796f356739c4734f.svg?invert_in_darkmode" align=middle width=119.69219789999998pt height=22.831056599999986pt/>O(n^2 log(n))<img src="svgs/9da71f57164fd15019956af4478e3ef6.svg?invert_in_darkmode" align=middle width=347.48952644999997pt height=87.12328680000002pt/>S$ where repeated subsequences appear)

- key-word in context
  - can use an inverted index (an alphabetical listing of all word that appear, together with the line numbers at which they appear)

## Ternary quicksort

*TODO:* how is this related?

- choose only 1 letter as a pivot, rather than the whole word..

- then we have the less than, equal to first letter, and greater than sides. hence *ternary* quicksort.

- then there is a parameter called `depth` - controls which letter of the word we are sorting at.