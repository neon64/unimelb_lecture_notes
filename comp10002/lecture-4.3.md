# Lecture 4.3

## Defining efficiency

<img src="svgs/47c124971e1327d1d3882a141f95face.svg?invert_in_darkmode" align=middle width=18.08608559999999pt height=21.18721440000001pt/> is the same as <img src="svgs/f3ec81197a9535e6ac2e60e76942fbc5.svg?invert_in_darkmode" align=middle width=158.4248457pt height=24.995338500000003pt/> - we say that both are linear


To capture this idea we define sets of functions that are all asymptotically equivalent in terms of their eventual long term growth rate:

<p align="center"><img src="svgs/0e3e769a2c5528ea07fa0c579445ad01.svg?invert_in_darkmode" align=middle width=109.42438649999998pt height=16.438356pt/></p>

if and only if

<p align="center"><img src="svgs/05a9bbf251e467917e17dd3c720b905a.svg?invert_in_darkmode" align=middle width=254.5487142pt height=16.438356pt/></p>

This is a complex definition!

Other notes regarding time complexities:

- binary logs are our best friend: <img src="svgs/6da5fdcc1674c95bf1531ddb72ea1fe2.svg?invert_in_darkmode" align=middle width=46.445981999999994pt height=22.831056599999986pt/>

- <img src="svgs/c9fed40c92321e6e6be70202e76fb6ff.svg?invert_in_darkmode" align=middle width=70.41855149999999pt height=22.831056599999986pt/> - is that really useful?

- <img src="svgs/1e8d99d9344bf6d7d24a8a713620dd3b.svg?invert_in_darkmode" align=middle width=54.66519134999999pt height=22.831056599999986pt/> - iterated log

## Types of analysis

1. Best case: of academic interest only

> "if you rely on best-case analysis, you're a mug"

2. Average case:

   1. randomness required in input: high risk unless input guaranteed

   2. randmness enforced by algorithm, regardless of input

3. Worst case: bet your friend's life on it

## Premature optimisation

*premature optimisation* - when one looks at one tiny operation and tries to improve it, but the whole overall algorithm is crap.

thus, one should **avoid premature optimisation**.


## Time complexity of sorting algorithms.

Insertion sort is <img src="svgs/3987120c67ed5a9162aa9841b531c3a9.svg?invert_in_darkmode" align=middle width=43.02219404999999pt height=26.76175259999998pt/> - but not that bad for small <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>.

Quicksort is <img src="svgs/ff514eba41c59f90c20d895e80719763.svg?invert_in_darkmode" align=middle width=72.2268393pt height=24.65753399999998pt/> best and average case, but <img src="svgs/3987120c67ed5a9162aa9841b531c3a9.svg?invert_in_darkmode" align=middle width=43.02219404999999pt height=26.76175259999998pt/> worst case.


>  "there's probably someone in the room with an IQ of 237, but most definitely not me - too much alcohol in my brain"
>
> - Alistair

