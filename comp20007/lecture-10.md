# Lecture 10 - Master Theorem

Consider an arbitrary divide-and-conquer algorithm which splits up work into <img src="svgs/44bc9d542a92714cac84e01cbbb7fd61.svg?invert_in_darkmode" align=middle width=8.68915409999999pt height=14.15524440000002pt/> subproblems of size <img src="svgs/b0d608abbdaaf83496cdc80639d16f9c.svg?invert_in_darkmode" align=middle width=8.126022299999999pt height=22.853275500000024pt/> , taking <img src="svgs/3d425a215e8eeb2a056f553633aaae4a.svg?invert_in_darkmode" align=middle width=32.46972299999999pt height=24.65753399999998pt/> operations to do the splitting/combining:

<p align="center"><img src="svgs/20e775cb345fa917b863f4405a2bd840.svg?invert_in_darkmode" align=middle width=177.65706914999998pt height=30.1801401pt/></p>

e.g.: a common case could be (dividing each problem into 2 equal subproblems, combine step takes <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> operations)

<p align="center"><img src="svgs/4fb4b225b69b08f62bd7f8ef4b08fa43.svg?invert_in_darkmode" align=middle width=142.71229499999998pt height=30.1801401pt/></p>

Can we find the closed forms for these recurrence relations more quickly than solving them by hand?

## Master Theorem

Integer constants <img src="svgs/39bb5e81f5adbfbf5d18a3a54acb5aa6.svg?invert_in_darkmode" align=middle width=38.82599489999999pt height=21.18721440000001pt/>, <img src="svgs/bb7940a01548a7a4db973e55d2e5b1b5.svg?invert_in_darkmode" align=middle width=37.19163689999999pt height=22.831056599999986pt/>. A function <img src="svgs/190083ef7a1625fbc75f243cffb9c96d.svg?invert_in_darkmode" align=middle width=9.81741584999999pt height=22.831056599999986pt/> with <img src="svgs/3222c0344adc39fe52a8586ba9aea19c.svg?invert_in_darkmode" align=middle width=141.66228615pt height=27.91243950000002pt/>

then

<p align="center"><img src="svgs/766d74b5990c2c2777f7eb14ed2dec8f.svg?invert_in_darkmode" align=middle width=167.5249455pt height=16.438356pt/></p>

has solutions, and

<p align="center"><img src="svgs/6709a9f2b429ea0b5f2f0415508f1656.svg?invert_in_darkmode" align=middle width=221.67904935pt height=69.0417981pt/></p>

### Examples

<p align="center"><img src="svgs/fca4514fb68058bbf9c37dd880b395a8.svg?invert_in_darkmode" align=middle width=274.93876905pt height=16.438356pt/></p>

<p align="center"><img src="svgs/c4f2ee8277825793dc64f47f392e922e.svg?invert_in_darkmode" align=middle width=72.01684875pt height=16.438356pt/></p>

<p align="center"><img src="svgs/979958ca17e418624154bd034af77d73.svg?invert_in_darkmode" align=middle width=346.95561614999997pt height=16.438356pt/></p>

<p align="center"><img src="svgs/3933fd1c6084c6c1e3d0deef60c4377a.svg?invert_in_darkmode" align=middle width=347.8878117pt height=18.312383099999998pt/></p>

<p align="center"><img src="svgs/edc006d423ff631c4a2a1d132aa5d4b3.svg?invert_in_darkmode" align=middle width=423.9650613pt height=18.312383099999998pt/></p>

Amount of work to subdivide is quadratic:

<p align="center"><img src="svgs/5c2fd6ed1740ef5dd14a9ecf9113e7ea.svg?invert_in_darkmode" align=middle width=195.80323125pt height=18.312383099999998pt/></p>

## Recursion Tree

<p align="center"><img src="svgs/6d602cd5ed2e110939ce4a8e681f987e.svg?invert_in_darkmode" align=middle width=152.1691149pt height=18.312383099999998pt/></p>

What is the height of the tree? <img src="svgs/e0d033354415a73a22d6601c874f16ed.svg?invert_in_darkmode" align=middle width=51.25968044999999pt height=24.65753399999998pt/>

Costs:

<p align="center"><img src="svgs/b6144d77ce370f90f9d6b65fc208a6f8.svg?invert_in_darkmode" align=middle width=466.11424695pt height=18.312383099999998pt/></p>

So <img src="svgs/3987120c67ed5a9162aa9841b531c3a9.svg?invert_in_darkmode" align=middle width=43.02219404999999pt height=26.76175259999998pt/>

Also see - *general recursion tree* to develop an intuition for the master theorem

Each of the leaves of the tree is <img src="svgs/8baa6519095a4bdbc7392b4a8b5116dc.svg?invert_in_darkmode" align=middle width=33.79007609999999pt height=24.65753399999998pt/>.

We have <img src="svgs/bf54265e2692fffe24db584c6ab70766.svg?invert_in_darkmode" align=middle width=123.40576874999998pt height=29.190975000000005pt/> instances, 

​    (NOTE: how to prove that, take <img src="svgs/204fcab26db8319fad7f6222b4b6e563.svg?invert_in_darkmode" align=middle width=40.42514519999999pt height=24.65753399999998pt/> of both sides of the equation)

At leaf level - 

<p align="center"><img src="svgs/4d1e8818db935950354b9e4e49d3af93.svg?invert_in_darkmode" align=middle width=227.6421015pt height=52.22619105pt/></p>

If <img src="svgs/906faa2324bfffbb87ee547e1da48397.svg?invert_in_darkmode" align=middle width=44.50465964999999pt height=27.91243950000002pt/>, <img src="svgs/167d52695bfec0f8aa279450c96d59ee.svg?invert_in_darkmode" align=middle width=73.01128889999998pt height=27.91243950000002pt/>.

<p align="center"><img src="svgs/7dabc3f9593f770570cee695dea115b9.svg?invert_in_darkmode" align=middle width=506.54573969999996pt height=50.947635749999996pt/></p>

RH term dominates the LH term so <img src="svgs/ceb9d5872f8cb918bee459448830218b.svg?invert_in_darkmode" align=middle width=117.17296139999999pt height=27.91243950000002pt/>