# SageMath: Symbolic Mathematics and Plotting

## What is SageMath?

SageMath (formerly SAGE) is a free, open-source mathematics software system licensed under the GPL. It integrates numerous mathematical libraries (such as NumPy, SymPy, PARI, GAP, and Matplotlib) into a unified Python-based interface. SageMath supports symbolic computation, numerical analysis, graph theory, linear algebra, calculus, and more.

## What is it used for?

SageMath is widely used for:
- **Symbolic algebra**: solving equations, simplifying expressions
- **Calculus**: computing derivatives, integrals, limits
- **Linear algebra**: matrix operations, eigenvalues, decompositions
- **Plotting**: 2D/3D graphs of functions and data
- **Number theory and cryptography**
- **Discrete mathematics**: graph/network analysis
- **Education and research** in pure and applied mathematics

It serves as a free alternative to commercial systems like Mathematica, Maple, or MATLAB.

## How to Use SageMath

SageMath code resembles Python but with built-in support for symbolic variables and mathematical functions. 
For example:

plot_function.sage

x = var('x')
f = sin(x)^2 + cos(x)^2
print(f.simplify_trig())  

save the file as .sage extension and run using

sage plot_function.sage