# Lecture 20 - More on Dynamic Programming

## Knapsack problem

- brute-force would enumerate all possible subsets
  - <img src="svgs/f8f25e4580c418a51dc556db0d8d2b93.svg?invert_in_darkmode" align=middle width=16.34523329999999pt height=21.839370299999988pt/> possible subsets
  - exponential complexity - Not Good

Given <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> items with

- weights <img src="svgs/ad3cf9ca9aa5cfb1c90765ff31798693.svg?invert_in_darkmode" align=middle width=94.70988284999999pt height=14.15524440000002pt/> (all positive integers)
- values <img src="svgs/29c2fb83442090d37b5f4c9e1ab919f4.svg?invert_in_darkmode" align=middle width=90.61444094999999pt height=14.15524440000002pt/> (all positive integers)
- knapsack of capacity <img src="svgs/84c95f91a742c9ceb460a83f9b5090bf.svg?invert_in_darkmode" align=middle width=17.80826024999999pt height=22.465723500000017pt/>

Find the **most valuable selection of items that will fit in the knapsack**.

Need to use **two variables** for this particular dynamic programming problem.

- <img src="svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663225699999989pt height=21.68300969999999pt/> - index into the weights/values array
- <img src="svgs/36b5afebdba34564d884d347484ac0c7.svg?invert_in_darkmode" align=middle width=7.710416999999989pt height=21.68300969999999pt/> capacity left

Express the solution recursively:
<p align="center"><img src="svgs/81e9295dae73d76712b65cf25a570d1e.svg?invert_in_darkmode" align=middle width=198.55055055pt height=16.438356pt/></p>


Otherwise
<p align="center"><img src="svgs/8ab6f2d5bd7f96d5497700847dc605e9.svg?invert_in_darkmode" align=middle width=438.61362269999995pt height=49.315569599999996pt/></p>
- if the <img src="svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663225699999989pt height=21.68300969999999pt/>th item could fit in the knapsack, return the highest value between including it in the knapsack, and not including it in the knapsack.
- otherwise if the <img src="svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663225699999989pt height=21.68300969999999pt/>th item could not possibly fit in the knapsack (<img src="svgs/351e133a641820c135ae846cc2fd5b03.svg?invert_in_darkmode" align=middle width=46.04745584999999pt height=21.68300969999999pt/>), then value is the problem skipping the <img src="svgs/930303c1b2e611a8c8b5b1708041319e.svg?invert_in_darkmode" align=middle width=21.07043894999999pt height=22.831056599999986pt/> item.



Bottom-up solution: fill in the rows and columns of an <img src="svgs/3f18d8f60c110e865571bba5ba67dcc6.svg?invert_in_darkmode" align=middle width=38.17727759999999pt height=21.18721440000001pt/> rows and <img src="svgs/11ee98da0c1b828029817d1d4b6f0342.svg?invert_in_darkmode" align=middle width=46.118658299999986pt height=22.465723500000017pt/> columns

-  but lots of wasted calculations

Top-down, with *memoing* (memoization?)

Can make the memo table small by using a hash-table

<p align="center"><img src="svgs/b76a4529256edd6cd56489d609a3385c.svg?invert_in_darkmode" align=middle width=66.03143415pt height=16.438356pt/></p>


- <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> - number of items 
- <img src="svgs/84c95f91a742c9ceb460a83f9b5090bf.svg?invert_in_darkmode" align=middle width=17.80826024999999pt height=22.465723500000017pt/> - max capacity of the knapsack

called pseudopolynomial time - the algorithm is polynomial in the *value* of the input, not its length

- is really <img src="svgs/b2838ae00727c036aefbd8c2f3c4d110.svg?invert_in_darkmode" align=middle width=176.64590624999997pt height=27.91243950000002pt/>
- counting sort is another example
- pseudopolynomial is not in general polynomial because it is exponential in the number of bits.

[pseudo-polynomial on StackOverflow](https://stackoverflow.com/questions/19647658/what-is-pseudopolynomial-time-how-does-it-differ-from-polynomial-time)





Actual definition of time complexity: *amount of time it takes for an algorithm to run, as a function of the **length** of its input in bits*.



e.g.:

```pseudocode
function doSomething(n):
	for 1 to n:
		print(n)
		
doSomething(4) // length of input is 3, but runs 4 times
doSomething(8) // length of input is 4, but runs 8 times
doSomething(16) // length of input is 5, but runs 16 times
```

- this algorithm has exponential time complexity - <img src="svgs/2f194f9223eba47a20f3e657bd7164e5.svg?invert_in_darkmode" align=middle width=140.70605834999998pt height=27.91243950000002pt/>
- 