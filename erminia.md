---
title: Erminia
layout: page
---

# A Domain-Specific Language for interpreting ARC-AGI abstracted Images as code

The Erminia DSL is a collection of software tools and libraries designed to 
facilitate the interpretation of ARC-AGI abstracted images as code. The primary
motivation for creating this language is the inherent ability of LLMs to predict 
and generate code snippets, as opposed to interpreting images directly. 

## Overview

Erminia provides a set of abstractions and constructs that allow users to represent
visual elements in the ARC-AGI dataset as objects on the given grid. This is done by 
the user instantiating an object, naming it and specifying its coordinates and colors.
The user has at their disposal a variety of functions called `primitives`, that allow
him to manipulate objects in various ways, such as moving them around the grid,
changing their colors, rotating them, etc.

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
