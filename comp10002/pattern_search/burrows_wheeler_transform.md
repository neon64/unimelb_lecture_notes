# Burrows-Wheeler transform

Let $L[i]$ be the character that immediately precedes the suffix $T[i...]$. If the suffix is the whole string, then, we wrap around and use the final character `!` instead.

Sort the Burrows-Wheeler transform...

![image](./screenshot_2019-11-10_17-04-43_004207443.png)

## Can reconstruct the original text! From this thing.

- goes through a deterministic procedure, where many similar symbols get grouped together.
  - happens because burrows wheeler transform comes from the *suffix array*
- this can then be compressed / decompressed by avoiding repeated chars
- then apply inverse burrows wheeler transform back to get the original text



```
sells_sea_shells

s$
ls$
lls$
ells$
hells$
shells$
_shells$
a_shells$
ea_shells$
sea_shells$
_sea_shells$
s_sea_shells$
ls_sea_shells$
lls_sea_shells$
ells_sea_shells$
sells_sea_shells$

- sorting the suffix array

0     s  $
8     e  a_shells$
9     s  ea_shells$
4     h  ells$
15    s  ells_sea_shells$
5     s  hells$
3     e  lls$
14    e  lls_sea_shells$
2     l  ls$
13    l  ls_sea_shells$
1     l  s$
10    _  sea_shells$
16    $  sells_sea_shells$
6     _  shells$
12    l  s_sea_shells$
11    s  _sea_shells$
7     a  _shells$

1 1 2 1 3 4 2 3 1 2 3 1 1 2 4 5 1
s e s h s s e e l l l _ $ _ l s a

1 1 1 2 3 1 1 2 3 4 1 2 3 4 5 1 2
$ a e e e h l l l l s s s s s _ _


sells_sea_shells$

```


