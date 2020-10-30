# Lecture 11.2 -  problem-solving, algorithms and more

Some problem solving techniques:

1. Generate and test
2. Divide and conquer

## Subset sum problem

> Is there a subset of the following numbers that adds up to exactly 1,000?

```c
int subsetsum(int A[], int n, int k) {
    if(k == 0) {
        return 1;
    } else if(n==0) {
        return 0;
    } else {
        return subsetsum(A, n-1, k-A[n-1]) || subsetsum(A, n-1, k)
    }
}
```

- worst case - grows exponentially

- we haven't developed better algorithms to solve these problems, because they just have exponential complexity

- another one is solving all constraints for e.g.: exam timetabling


### Divide and conquer approach

Evaluate all subsets of the <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> items, and if any oone of them adds to <img src="svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075367949999992pt height=22.831056599999986pt/>, return "yes"

Either the last value `A[n-1]` is part of the sum, or it is not.

If it is, a subset sum on the first n-1 items in the arra must add to `k - A[n-1]`

Subset sum problem is an example of a very important class of related **hard** problems. Exponential time with size of input - therefore we call them *intractable*. They can be *verified* quickly though...

If any one of these problems can be solved in polynomial time, then they all can.

Important task - proving `P = NP`

*tractable* - easy to solve or deal with

## Monte Carlo methods

- use a pseudo-random number generator to allow modelling a physical system

- `srand`, then `rand`

## Spring simulation

- can set the timestep manually...

## A different way to do multiplication

```
  123
  654
-----
  492
 615
738
-----
80442
```

have done <img src="svgs/3987120c67ed5a9162aa9841b531c3a9.svg?invert_in_darkmode" align=middle width=43.02219404999999pt height=26.76175259999998pt/> single digit multiplications to multiply some big number...

1. split <img src="svgs/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode" align=middle width=9.39498779999999pt height=14.15524440000002pt/> and <img src="svgs/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode" align=middle width=8.649225749999989pt height=14.15524440000002pt/> into two halves of digits, <img src="svgs/d6d54860f3796e33548482099695dec5.svg?invert_in_darkmode" align=middle width=26.30529494999999pt height=24.65753399999998pt/> digits each

   - $x = a \cdot 10^{n/2} + b$

   - $y = c \cdot 10^{n/2} + d$

Then we get

<p align="center"><img src="svgs/59d9e6b58de3c32b709fa3d0eeb5b53a.svg?invert_in_darkmode" align=middle width=700.2744869999999pt height=19.526994300000002pt/></p>

if <img src="svgs/600979b5b6b2bf60cc96e3ebb182b871.svg?invert_in_darkmode" align=middle width=40.00371704999999pt height=21.18721440000001pt/>, was doing 36 multiplications

here, <img src="svgs/a0e4745ed05585ebe7beb1f95478e5e6.svg?invert_in_darkmode" align=middle width=84.74508569999999pt height=22.831056599999986pt/> each take 9 multiplications

<p align="center"><img src="svgs/961869f8fbd8f085e915b08525340458.svg?invert_in_darkmode" align=middle width=654.9607251pt height=16.438356pt/></p>

Then we get to reuse <img src="svgs/42fe8de64108aefb2d92fe965dedb3d8.svg?invert_in_darkmode" align=middle width=15.80295914999999pt height=14.15524440000002pt/> and <img src="svgs/383ed341a87d658866df5a9f424ef857.svg?invert_in_darkmode" align=middle width=14.16860114999999pt height=22.831056599999986pt/>

```
ad+bc = (a+b)(c+d) - ac -bd
         n/2   n/2   ^ already had these values
```

How many multiplications are we doing?

<p align="center"><img src="svgs/0aee1c393e4cb577e02487959c357b49.svg?invert_in_darkmode" align=middle width=257.7150807pt height=16.438356pt/></p>

Complexity is <img src="svgs/8dc0d88e90558e9029e7e3774c23b9da.svg?invert_in_darkmode" align=middle width=158.66432504999997pt height=29.190975000000005pt/>

