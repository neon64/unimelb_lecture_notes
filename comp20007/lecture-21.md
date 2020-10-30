# Lecture 21 - P=NP?



- decision problems
  - is there a hamiltonian path?
  - is the integer <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> a prime number?



- optimisation problems can be framed as a sequence of decision problems



- verification problems takes an input, a <u>proposed solution</u> and verifies if the solution satisfies the inpt
  - given <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> and <img src="svgs/1faba647ad0d139077f8b29823fb3aff.svg?invert_in_darkmode" align=middle width=82.83992804999998pt height=21.68300969999999pt/> check if <img src="svgs/c7990fdbb3b348b457a1782da0e0d5fb.svg?invert_in_darkmode" align=middle width=49.77653174999998pt height=22.465723500000017pt/>
  - verify that there is a circuit that follows the given sequence of nodes



now can define what is **P** and what is **NP**



**P** - if the decision version of the problem has a solution that is polynomial in the input size

**NP** - if its verification version has a solution which is polynomial in the input size

(can be verified in polynomial time)



![img](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a0/P_np_np-complete_np-hard.svg/1920px-P_np_np-complete_np-hard.svg.png)

We can turn a verification problem into a decision problem:

 - a non-deterministic Turing machine generates a candidate
   	- could generate all candidates in parallel
	- the verification algorithm verifies the solution
	- repeat until verified



**NP** - its decision version which is non-deterministically polynomial in the input size (that's where the N in NP comes from)




<p align="center"><img src="svgs/f45d1fadea441732be2208d1aae2969c.svg?invert_in_darkmode" align=middle width=40.6735164pt height=11.232861749999998pt/></p>

- one can verify a solution by solving the decision version and comparing the result to make sure they're equal.



- the reverse is unknown <img src="svgs/e7576f99d0541fea7c778615acb5b1af.svg?invert_in_darkmode" align=middle width=57.56830364999999pt height=22.831056599999986pt/> 



Is P = NP?



## Reductions

daunting task to try and prove bounds for every new problem



- hamiltonian circuit (HAM) problem can be reduced to a decision version of TSP
- reduction function is polynomial, therefore since HAM is in NP, the decision version of TSP is also in NP



- ask the travelling salesman problem: "is there a circuit that visits all nodes only once with a weight of at most 0"

  - ends up solving HAM for you

  - if path length is not 0, then we have travelled down one of the non-connected nodes which we gave an edge weight of 1.



## NP-completeness

- <img src="svgs/9414c5274567a73a161305f80e4a4b82.svg?invert_in_darkmode" align=middle width=61.99411349999998pt height=22.465723500000017pt/> and
  - every problem has a polynomial reduction to <img src="svgs/78ec2b7008296ce0561cf83393cb746d.svg?invert_in_darkmode" align=middle width=14.06623184999999pt height=22.465723500000017pt/> or
  - a polynomial reduction from a known NP-complete problem to D exists

Key property: if one finds a polynomial time algorithm to solve an NP-complete problem, then P=NP as every problem in NP can be reduced to this polynomial time algorithm.





**boolean 3-satisfiability problem** - **(3-SAT)**

	- given a boolean formula with a maximum of 3 literals, is there an assignment that results in TRUE?







- SAT
- Clique
- VertexCover
- Hamiltonian Circuit
- Decision-TSP





## NP-hardness

- at least as hard as the hardest problems in NP, they do not have to be elements of NP, indeed, they may not even be decidable.
- NP-complete = in NP, and NP-hard
- whereas NP-hard problems may not be in NP,
- example: halting problem is NP-hard but not NP-complete, since it is not decidable



## Recap

- complexity theory - deals with **bounds** for problems

- some problems are undecidable: 

see COMP30026

- canonical example - the halting problem

- some scientists tried to prove that P?NP is undecidable
- most scientists believe that <img src="svgs/4227598663238df6d25418ac887d010c.svg?invert_in_darkmode" align=middle width=62.59114619999999pt height=22.831056599999986pt/>



