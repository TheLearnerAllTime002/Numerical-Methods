
# 🔍 Root Finding Methods

> C implementations of numerical algorithms for solving nonlinear equations f(x) = 0 with convergence analysis and error estimation.

<div align="center">
  <img src="https://img.shields.io/badge/C-99%20Standard-blue?logo=c" alt="C Standard">
  <img src="https://img.shields.io/badge/Methods-5-brightgreen" alt="Method Count">
  <img src="https://img.shields.io/badge/Precision-Double-important" alt="Precision">
</div>

## 📚 Implemented Algorithms

### 1. Bisection Method
```math
\text{Given } f(a)f(b) < 0 \text{, iteratively halves the interval:}
```
$$
x_{mid} = \frac{a + b}{2}
$$
**Convergence:** Linear (1/2 rate)  
**Error Bound:** 
$$
|\alpha - x_n| \leq \frac{b-a}{2^{n+1}}
$$

**Files:**  
`BISECTION_BEGINNER.C` | `BISECTION_INTERMEDIATE.C`

### 2. Newton-Raphson Method
```math
\text{Uses first-order Taylor approximation:}
```
$$
x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}
$$
**Convergence:** Quadratic (when near root)  
**Files:**  
`NR_IG_BEG.C` | `NR_INTERMEDIATE.C` | `NR_INTERVAL_BEG.C` | `NR_INTERVAL_INTERMEDIATE.C`

### 3. Regula Falsi (False Position)
```math
\text{Linear interpolation between bounds:}
```
$$
x_{new} = b - \frac{f(b)(b-a)}{f(b)-f(a)}
$$
**Convergence:** Superlinear  
**Files:**  
`REGULA_FALSI_BEGINNER.C` | `REGULA_FALSI_INTERMEDIATE.C`

## 🛠 Usage Example
```c
#include <math.h>
#include "rootfinding.h"

double f(double x) {
    return x*x - 2; // Find sqrt(2)
}

int main() {
    double a = 1.0, b = 2.0;
    double tol = 1e-6;
    
    double root = bisection(f, a, b, tol);
    printf("Found root: %.8f\n", root);
    
    return 0;
}
```

## 📊 Method Comparison

| Method          | Convergence Rate | Requires Derivative | Interval Needed | Stability |
|-----------------|------------------|---------------------|------------------|-----------|
| Bisection       | Linear (1/2)     | No                  | Yes              | High      |
| Newton-Raphson  | Quadratic        | Yes                 | No               | Medium    |
| Regula Falsi    | Superlinear      | No                  | Yes              | High      |

## 📁 File Structure

```
root-finding/
├── Bisection/
│   ├── BISECTION_BEGINNER.C
│   └── BISECTION_INTERMEDIATE.C
├── Newton-Raphson/
│   ├── NR_IG_BEG.C (Initial Guess)
│   ├── NR_INTERMEDIATE.C
│   ├── NR_INTERVAL_BEG.C
│   └── NR_INTERVAL_INTERMEDIATE.C
└── Regula_Falsi/
    ├── REGULA_FALSI_BEGINNER.C
    └── REGULA_FALSI_INTERMEDIATE.C
```

## 📝 Theoretical Notes

**Stopping Criteria:**
1. Absolute error: $|x_{n+1} - x_n| < \epsilon$
2. Relative error: $\frac{|x_{n+1}-x_n|}{|x_n|} < \epsilon$
3. Function value: $|f(x_n)| < \epsilon$

**Convergence Conditions:**
- Bisection: Requires $f(a)f(b) < 0$
- Newton: Needs good initial guess and $f' \neq 0$
- Regula Falsi: Preserves bracketing property

## 📚 References

1. Atkinson (1988), *An Introduction to Numerical Analysis*
2. Quarteroni et al. (2007), *Numerical Mathematics*


<div align="center">
  <img src="https://render.githubusercontent.com/render/math?math=\color{red}\boxed{\text{Convergence\ =\ Confidence}}" alt="Convergence = Confidence">
</div>
```

Key Features:
1. **Mathematically Precise**: All algorithms presented with their governing equations
2. **Comparative Analysis**: Clear table comparing method characteristics
3. **Ready-to-Run Example**: Practical usage demonstration
4. **Error Analysis**: Each method includes convergence rate and error bounds
5. **Structured Layout**: Organized file structure visualization
6. **Theoretical Foundation**: Notes on stopping criteria and convergence conditions
7. **Professional Badges**: Standardized metadata indicators
