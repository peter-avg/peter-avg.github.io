---
title: Overview
layout: page
permalink: /erminia/overview/
---

## Overview

Erminia provides a set of abstractions and constructs that allow users to represent
visual elements in the ARC-AGI dataset as objects on the given grid. This is done by 
the user instantiating an object, naming it and specifying its coordinates and colors.
The user has at their disposal a variety of functions called `primitives`, that allow
him to manipulate objects in various ways, such as moving them around the grid,
changing their colors, rotating them, etc.

The structure of an Erminia program, as shown later through examples and grammar,
is composed by the declaration of examples inside a problem statement scope. Each
example contains an input and an output section, and the user may use the declared 
objects and standard library primitives to interpret the input and output image as code.

### Program Structure



```cpp




```

### Object Declaration

An example of this would be the following code snippet:

```cpp
object Square {
    shape: [(0, 0), (0, 1), (1, 0), (1, 1)],
    color: "blue"
}

let sq: object = Square()
draw(sq)
```

### Primitives

An example of a primitive would be the `move_left` function, which moves
an object one unit to the left on the grid:

```cpp
move_left(sq)
```
