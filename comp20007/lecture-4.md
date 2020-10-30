# Lecture 4 - Complexity Analysis (12/03/2020)

### RAM Model of Computation

>  The RAM (Random Access Machine) model of computation measures the run time  of an algorithm by summing up the number of steps needed to execute the  algorithm on a set of data.
> 
> Basic logical or arithmetic operations (+, *, =, if, call) are considered to be simple operations that take one time step.
> All memory operations take exactly one time step.

### Counting "Basic Operations"

- take the most expensive operation, and only count occurrences of that operation
- what use in this subject

### Key ideas

Large input is what matters! Large input reveals the tyranny of a high growth rate.

When analyzing algorithms, it is important to:

- Ignore constant factors
- Ignore small input sizes

We tend to use the 'element of' notation:  <img src="svgs/d1492d9fdcf06ec062683b5d2b1a9fbf.svg?invert_in_darkmode" align=middle width=105.54307005pt height=24.65753399999998pt/> 

Some textbooks use <img src="svgs/f00b8adb9349e8f743b2f117be779afb.svg?invert_in_darkmode" align=middle width=107.36956394999999pt height=24.65753399999998pt/> - to show that it is an upperbound, not a tight upper bound.

It is correct to say <img src="svgs/14df78053fa7f9dad5a3847f49c5f7f4.svg?invert_in_darkmode" align=middle width=81.19941884999999pt height=26.76175259999998pt/>, but incorrect to say <img src="svgs/acfc6bfb00fbed874725947577f1959e.svg?invert_in_darkmode" align=middle width=83.02591109999999pt height=26.76175259999998pt/>.

Can also use <img src="svgs/68ba515c8d6a3b8f94091ca8912810b7.svg?invert_in_darkmode" align=middle width=41.89894829999999pt height=26.76175259999998pt/> for *lower* bounds.

<img src="svgs/7f673488709d91c2cf326d97e5a437c3.svg?invert_in_darkmode" align=middle width=42.81220349999999pt height=26.76175259999998pt/> for *exact* order of growth - so it is bounded on both sides by some <img src="svgs/8a8560f3472583546183551f4d9abb22.svg?invert_in_darkmode" align=middle width=15.333014399999989pt height=21.18721440000001pt/> and <img src="svgs/6d4c82c9ed6b4af87fd13412eadd02b0.svg?invert_in_darkmode" align=middle width=15.333014399999989pt height=21.18721440000001pt/>:

![](Screenshot from 2020-03-13 19-53-59.png)

## **Example with big-O notation:**

Show that <img src="svgs/10f3f9024b153145aa361a7d7e9cfd09.svg?invert_in_darkmode" align=middle width=168.87019049999998pt height=26.76175259999998pt/>.

<p align="center"><img src="svgs/3d14d34ac715a17f294c53fd203c798a.svg?invert_in_darkmode" align=middle width=282.58569075pt height=44.89738935pt/></p>

Choose <img src="svgs/d73e5f343466c98c7c2bc808f2f8b54f.svg?invert_in_darkmode" align=middle width=37.25064419999999pt height=21.18721440000001pt/> or something and then you can prove by first-principles.

(we shouldn't really choose <img src="svgs/2a24f4b966bec8b31d29ed41eb258910.svg?invert_in_darkmode" align=middle width=37.25064419999999pt height=21.18721440000001pt/> because initially the terms will be equal not less than, and our condition below requires a strict less-than. so to be safe - choose a higher value for <img src="svgs/3e18a4a28fdee1744e5e3f79d13b9ff6.svg?invert_in_darkmode" align=middle width=7.11380504999999pt height=14.15524440000002pt/>)

<p align="center"><img src="svgs/07c84a6248056107085a1bbf249f27fd.svg?invert_in_darkmode" align=middle width=194.3489064pt height=16.438356pt/></p>

### Maths note: changing base of logarithm

<p align="center"><img src="svgs/ac8d8d8496bd1f9ef4e0f56844e02f64.svg?invert_in_darkmode" align=middle width=562.58816295pt height=38.74356255pt/></p>

### Another approach to establish growth rate

Can prove that <img src="svgs/d1492d9fdcf06ec062683b5d2b1a9fbf.svg?invert_in_darkmode" align=middle width=105.54307005pt height=24.65753399999998pt/> for some <img src="svgs/5535e846779a3cde954cc9e82ba77c7d.svg?invert_in_darkmode" align=middle width=21.67235729999999pt height=20.221802699999984pt/> using the definition of <img src="svgs/9afe6a256a9817c76b579e6f5db9a578.svg?invert_in_darkmode" align=middle width=12.99542474999999pt height=22.465723500000017pt/> directly

<p align="center"><img src="svgs/07c84a6248056107085a1bbf249f27fd.svg?invert_in_darkmode" align=middle width=194.3489064pt height=16.438356pt/></p>

There's another approach to show growth rate:

<p align="center"><img src="svgs/8a844761aa20aabfc6a7472b0c902115.svg?invert_in_darkmode" align=middle width=473.79387495pt height=69.0417981pt/></p>

We can show that <img src="svgs/68f1bbb87512454065f67d6f1803da9e.svg?invert_in_darkmode" align=middle width=41.21390624999999pt height=22.831056599999986pt/> grows slower than <img src="svgs/4fd78aba72015f7697ab298a89ec8a9c.svg?invert_in_darkmode" align=middle width=23.565549149999992pt height=24.995338500000003pt/>

<p align="center"><img src="svgs/a14da3539b7397437084974508106b09.svg?invert_in_darkmode" align=middle width=378.37203524999995pt height=46.98911085pt/></p>

therefore grows slower

- consider using L'Hopital's Rule to evaluate the limit

### Example: time complexity of selection sort

#### Steps

1. go through list, find the smallest element, put it at the front

2. repeat until list is sorted

#### Time Complexity

<p align="center"><img src="svgs/f2e819cc9b21a6712b97a855810e4e76.svg?invert_in_darkmode" align=middle width=257.2236282pt height=49.59602339999999pt/></p>

then, split the sum into two parts:

<p align="center"><img src="svgs/c3ad8c7684dbf25b0ceb8227377ee3db.svg?invert_in_darkmode" align=middle width=263.97692145pt height=47.35857885pt/></p>

<p align="center"><img src="svgs/fc86649425dce14c16bf44f7ad08a645.svg?invert_in_darkmode" align=middle width=376.23271124999997pt height=18.312383099999998pt/></p>

**Conclusion:** selection sort is <img src="svgs/7f673488709d91c2cf326d97e5a437c3.svg?invert_in_darkmode" align=middle width=42.81220349999999pt height=26.76175259999998pt/>