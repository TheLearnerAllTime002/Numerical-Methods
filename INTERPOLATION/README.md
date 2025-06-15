
# 📈 Numerical Interpolation Methods

> Collection of C implementations for polynomial interpolation methods with mathematical foundations and practical applications.

<div align="center">
  <img src="https://img.shields.io/badge/C-99%20Standard-blue?logo=c" alt="C Standard">
  <img src="https://img.shields.io/badge/License-MIT-green" alt="License">
  <img src="https://img.shields.io/badge/Version-1.0.0-orange" alt="Version">
</div>

## 📚 Implemented Methods

### 1. Lagrange Interpolation
Given `n+1` data points $(x_0,y_0),...,(x_n,y_n)$, the Lagrange polynomial is:

$$
L(x) = \sum_{i=0}^{n} y_i \ell_i(x)
$$

where $\ell_i(x)$ are the Lagrange basis polynomials:

$$
\ell_i(x) = \prod_{\substack{0 \leq j \leq n \\ j \neq i}} \frac{x - x_j}{x_i - x_j}
$$

**File:** `LAGRANGES_BEG.C`

### 2. Newton Forward Differences
For equally spaced points, the forward difference formula:

$$
P_n(x) = f[x_0] + \sum_{k=1}^n f[x_0,...,x_k] \prod_{i=0}^{k-1} (x - x_i)
$$

where divided differences are computed recursively.

**File:** `NF_BEGINNER.C`

### 3. Newton Backward Differences
Backward difference formula for endpoint interpolation:

$$
P_n(x) = f[x_n] + \sum_{k=1}^n f[x_n,...,x_{n-k}] \prod_{i=1}^k (x - x_{n-i+1})
$$

**Files:**
- `NB_BEGINNER.C` (Basic implementation)
- `NB_INTERMEDIATE.C` (Optimized version)

## 🛠 Usage Example

```c
#include <stdio.h>
#include "interpolation.h"

int main() {
    double x[] = {1.0, 2.0, 3.0};
    double y[] = {1.0, 4.0, 9.0};
    int n = 3;
    double xi = 2.5;
    
    double result = lagrange_interpolation(x, y, n, xi);
    printf("Interpolated value at x=%.1f: %.4f\n", xi, result);
    return 0;
}
```

## 📊 Error Analysis

The interpolation error is bounded by:

$$
|f(x) - P_n(x)| \leq \frac{|(x-x_0)\cdots(x-x_n)|}{(n+1)!} \max_{\xi\in[a,b]} |f^{(n+1)}(\xi)|
$$

## 📁 File Structure

```
interpolation/
├── LAGRANGES_BEG.C          # Basic Lagrange implementation
├── NF_BEGINNER.C            # Newton Forward Differences
└── Newton Backward/
    ├── NB_BEGINNER.C        # Basic Backward Differences
    └── NB_INTERMEDIATE.C    # Optimized Backward Differences
```

## 📝 References

1. Burden & Faires, "Numerical Analysis" (9th Ed.)
2. Stoer & Bulirsch, "Introduction to Numerical Analysis"
3. [Wolfram MathWorld - Polynomial Interpolation](https://mathworld.wolfram.com/PolynomialInterpolation.html)

<div align="center">
  <img src="https://render.githubusercontent.com/render/math?math=\color{green}\boxed{\text{Happy\ Interpolating!}}" alt="Happy Interpolating">
</div>
```

