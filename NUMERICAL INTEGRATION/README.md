
# ∫ Numerical Integration Methods

> C implementations of numerical quadrature methods for definite integrals with mathematical analysis and error bounds.

<div align="center">
  <img src="https://img.shields.io/badge/C-99%20Standard-blue?logo=c" alt="C Standard">
  <img src="https://img.shields.io/badge/Numerical-Methods-important" alt="Numerical Methods">
  <img src="https://img.shields.io/badge/Precision-Double-brightgreen" alt="Precision">
</div>

## 📚 Implemented Quadrature Methods

### 1. Trapezoidal Rule
Approximates the integral ∫ₐᵇ f(x)dx using linear approximations:

$$
\int_a^b f(x)dx \approx \frac{h}{2}\left[f(x_0) + 2\sum_{i=1}^{n-1}f(x_i) + f(x_n)\right]
$$

where $h = \frac{b-a}{n}$

**Error Term:**
$$
E_T = -\frac{(b-a)^3}{12n^2}f''(\xi), \quad \xi \in [a,b]
$$

**Files:**
- `TRAPEZOIDAL_BEGINNER.C` (Basic implementation)
- `TRAPEZOIDAL_INTERMEDIATE.C` (Adaptive version)

### 2. Simpson's 1/3 Rule
Uses quadratic polynomial approximations:

$$
\int_a^b f(x)dx \approx \frac{h}{3}\left[f(x_0) + 4\sum_{\text{odd }i}f(x_i) + 2\sum_{\text{even }i}f(x_i) + f(x_n)\right]
$$

**Error Term:**
$$
E_S = -\frac{(b-a)^5}{180n^4}f^{(4)}(\xi)
$$

**Files:**
- `SIMP_1_3_BEGINNER.C` (Fixed step)
- `SIMP_1_3_INTERMEDIATE.C` (Variable step)

### 3. Weddle's Rule
6th-order method using seven points per interval:

$$
\int_{x_0}^{x_6} f(x)dx \approx \frac{3h}{10}\left[f_0 + 5f_1 + f_2 + 6f_3 + f_4 + 5f_5 + f_6\right]
$$

**Files:**
- `WEEDLE_BEGINNER.C` (Basic implementation)
- `WEEDLE_INTERMEDIATE.C` (Composite version)

## 🛠 Usage Example

```c
#include "integration.h"

double f(double x) {
    return x*x; // Function to integrate
}

int main() {
    double a = 0.0, b = 1.0;
    int n = 100; // Number of partitions
    
    double result = trapezoidal(f, a, b, n);
    printf("Integral estimate: %.15f\n", result);
    
    return 0;
}
```

## 📊 Error Comparison

| Method          | Order | Error Term               | Best For                  |
|-----------------|-------|--------------------------|---------------------------|
| Trapezoidal     | 2     | O(h²)                    | Linear functions          |
| Simpson's 1/3   | 4     | O(h⁴)                    | Cubic polynomials        |
| Weddle's        | 6     | O(h⁶)                    | High-order smoothness    |

## 📁 File Structure

```
numerical-integration/
├── Trapezoidal/
│   ├── TRAPEZOIDAL_BEGINNER.C
│   └── TRAPEZOIDAL_INTERMEDIATE.C
├── Simpson's 1-3/
│   ├── SIMP_1_3_BEGINNER.C
│   └── SIMP_1_3_INTERMEDIATE.C
└── Weddle's/
    ├── WEEDLE_BEGINNER.C
    └── WEEDLE_INTERMEDIATE.C
```

## 📝 Theoretical Foundations

All methods approximate:

$$
\int_a^b f(x)dx \approx \sum_{i=0}^n w_i f(x_i)
$$

where $w_i$ are weights and $x_i$ are nodes. The methods differ in:
- Polynomial degree used
- Node distribution
- Weight calculations

## 📚 References

1. Press et al., "Numerical Recipes" (3rd Ed.)
2. Davis & Rabinowitz, "Methods of Numerical Integration"
3. [NIST Digital Library of Mathematical Functions](https://dlmf.nist.gov/)

<div align="center">
  <img src="https://render.githubusercontent.com/render/math?math=\color{blue}\boxed{\text{Precision\ =\ Power}}" alt="Precision = Power">
</div>
