# Burrows-Wheeler transform

[[back to pattern search]](./README.md)

- [Burrows-Wheeler transform (on Wikipedia)](https://en.wikipedia.org/wiki/Burrows%E2%80%93Wheeler_transform)

Let <img src="svgs/96dc587ba154217963a1c6e5a4866b63.svg?invert_in_darkmode" align=middle width=25.98291629999999pt height=24.65753399999998pt/> be the character that immediately precedes the suffix <img src="svgs/8358abd61954b67bce79fff9d08fba91.svg?invert_in_darkmode" align=middle width=40.383657599999985pt height=24.65753399999998pt/>. If the suffix is the whole string, then, we wrap around and use the final character `!` instead. See the image below:

![image1](screenshot_2019-09-18_11-17-27_753886358.png)

If we sort all of these <img src="svgs/96dc587ba154217963a1c6e5a4866b63.svg?invert_in_darkmode" align=middle width=25.98291629999999pt height=24.65753399999998pt/>s then we get a text that is more easily compressible (has more repeated letters)

![image](./screenshot_2019-11-10_17-04-43_004207443.png)

Example on a larger text:

![image2](screenshot_2019-09-18_18-22-56_199063098.png)

The amazing thing, is that you can reconstruct the original text From this thing!

- goes through a deterministic procedure, where many similar symbols get grouped together.
  - happens because burrows wheeler transform comes from the *suffix array*
- this can then be compressed / decompressed by avoiding repeated chars
- then apply inverse burrows wheeler transform back to get the original text

Example on `sells_sea_shells`


```
sells_sea_shells

s<img src="svgs/78e6c8edf4f4acaf16ce69b94cad9fc3.svg?invert_in_darkmode" align=middle width=12.93382364999999pt height=22.831056599999986pt/>
lls<img src="svgs/f03bb27acf37808eba30cd3219db9bc2.svg?invert_in_darkmode" align=middle width=25.81630589999999pt height=22.831056599999986pt/>
hells<img src="svgs/ba8f43a28e18d95dae8d48e92ab02f8b.svg?invert_in_darkmode" align=middle width=42.99290159999999pt height=22.831056599999986pt/>
_shells<img src="svgs/ed5801ec9d62aad3b85deaccc1fb6b1b.svg?invert_in_darkmode" align=middle width=51.00285959999998pt height=22.831056599999986pt/>
ea_shells<img src="svgs/261e7ae0858445dd35ded351582ec5af.svg?invert_in_darkmode" align=middle width=66.36247694999999pt height=22.831056599999986pt/>
_sea_shells<img src="svgs/39c9ee52a5a62a7940613995e9d0273b.svg?invert_in_darkmode" align=middle width=73.38875939999998pt height=22.831056599999986pt/>
ls_sea_shells<img src="svgs/bdfc60e38ae76ac0740747416b35ed54.svg?invert_in_darkmode" align=middle width=83.84544959999998pt height=22.831056599999986pt/>
ells_sea_shells<img src="svgs/9fecf56efe0896be506d2ee062be2cd8.svg?invert_in_darkmode" align=middle width=99.20506694999997pt height=22.831056599999986pt/>

- sorting the suffix array

0     s  <img src="svgs/0fbaa01cefb37ce28627779602bc7280.svg?invert_in_darkmode" align=middle width=66.87620609999998pt height=22.831056599999986pt/>
9     s  ea_shells<img src="svgs/256db7d561f359ab0b27be9e71a58490.svg?invert_in_darkmode" align=middle width=43.50663074999999pt height=22.831056599999986pt/>
15    s  ells_sea_shells<img src="svgs/2bbf3c24daeca152101d51baf0c2d926.svg?invert_in_darkmode" align=middle width=51.21211094999999pt height=22.831056599999986pt/>
3     e  lls<img src="svgs/26a659e98c6fb4c8b3e9f5f114ec1e91.svg?invert_in_darkmode" align=middle width=107.93800544999999pt height=22.831056599999986pt/>
2     l  ls<img src="svgs/8dbdd57ea3318330b57e209b4df2bd47.svg?invert_in_darkmode" align=middle width=100.28386829999998pt height=22.831056599999986pt/>
1     l  s<img src="svgs/41774dcc0b1578ef7dfa06598d4d8807.svg?invert_in_darkmode" align=middle width=82.12169954999999pt height=22.831056599999986pt/>
16    <img src="svgs/4decf320a8bd6321cf0f638619467020.svg?invert_in_darkmode" align=middle width=99.20506694999997pt height=22.831056599999986pt/>
6     _  shells<img src="svgs/0605d8bc6a2ee2f928a69d986359fdff.svg?invert_in_darkmode" align=middle width=95.05552319999998pt height=22.831056599999986pt/>
11    s  _sea_shells<img src="svgs/9c69e168ac8c5042d0ffcca37816d7af.svg?invert_in_darkmode" align=middle width=59.22206894999999pt height=22.831056599999986pt/>

1 1 2 1 3 4 2 3 1 2 3 1 1 2 4 5 1
s e s h s s e e l l l _ <img src="svgs/f2a8c7154a21863336c0a9928a27ee48.svg?invert_in_darkmode" align=middle width=219.17844959999996pt height=39.45205439999997pt/> a e e e h l l l l s s s s s _ _


# todo: explain how the reversing process works:

sells_sea_shells$

```


