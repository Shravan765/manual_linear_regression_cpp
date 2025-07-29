# Linear Regression (Normal Equation) in C++

This is a lightweight C++ implementation of **linear regression** using the **normal equation**, built entirely from scratch — no external libraries.

It fits a line of the form:
y = Ax + C
by minimising the squared error on a given set of training points.

---

## Features

- Implements the closed-form solution:  
θ = (XᵗX)⁻¹ Xᵗy

- Allows incremental or batch addition of `(x, y)` points
- Handles corner cases (e.g. no input, or only one repeated point)
- Easily extendable to multivariate regression

---

## 🛠️ Usage  
Check test.c++   


## Behaviour of return_constants()
If no points are added:  
Returns {0, 0} — dummy line when there's no data.  
  
If only one unique point is added (or the same point repeated):  
Returns {0, y} — horizontal line passing through the point.  
  
If two or more unique points are added:  
Computes and returns the slope A and intercept C using the normal equation.  

---
  
📂 File Overview  
linear_regression_manual.c++ – header+implementation of best_fitting_line class  

test.c++ – example usage  

---

  
📄 License  
MIT License. Free to use, modify, and share.  
