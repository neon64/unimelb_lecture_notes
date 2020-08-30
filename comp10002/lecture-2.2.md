# Lecture 2.2

Don't use `switch` - you will get penalised in the midsem test / exam!


Operator precedence:

```c
++ --
! - (type)
* / %
+ -
< > <= >=
== !=
&&
||
= += *=
```

suppose `x = 5`
```c
if (!(!x) == x) {
    // not necessarily always true
}
```



**Tip: sometimes just put parentheses around things to make things clear**

## Evaluation order

- Expressions involving `&&` and `||` are evaluated left to right
- The same is not necessarily true for other operators.
   - not necessarily the same on every machine: `(y++)*(y/=3)+(y--)*(y*=5)`

# Chapter 4 - Concepts

*for loops*: should have an invariant which is satisfied by initialisation, refined at each iteration, and when combined with the negation of the guard, represents the desired outcome.

Count from zero whenever possible, up to (but not including) `n`.

Loops to iterate over input - either by value or by character.

use `%6d` to right-justify, `%-6d` to left-justify


note, you can make a for loop run forever like so:

```c
for (;; ) {

}
```
