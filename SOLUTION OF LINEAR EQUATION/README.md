
# ➗ Linear Equation Solvers

> C implementations of direct and iterative methods for solving systems of linear equations (Ax = b) with numerical stability analysis.

<div align="center">
  <img src="https://img.shields.io/badge/C-99%20Standard-blue?logo=c" alt="C Standard">
  <img src="https://img.shields.io/badge/Methods-4-brightgreen" alt="Method Count">
  <img src="https://img.shields.io/badge/Precision-Double-important" alt="Precision">
</div>

## 📚 Implemented Algorithms

### 1. Gaussian Elimination
```math
\text{Transforms system to upper triangular form via row operations:}
```
$$
\begin{aligned}
\text{Forward Elimination} & : a_{ij}^{(k)} = a_{ij}^{(k-1)} - \frac{a_{ik}^{(k-1)}}{a_{kk}^{(k-1)}}a_{kj}^{(k-1)} \\
\text{Back Substitution} & : x_i = \frac{b_i - \sum_{j=i+1}^n a_{ij}x_j}{a_{ii}}
\end{aligned}
$$
**Complexity:** O(n³)  
**Files:**  
`GAUSS_ELIMINATION_BEG.C` | `GAUSS_ELIMINATION_ADV.C`

### 2. Gauss-Seidel Iterative Method
```math
\text{Iterative improvement of solution vector:}
```
$$
x_i^{(k+1)} = \frac{1}{a_{ii}}\left(b_i - \sum_{j=1}^{i-1}a_{ij}x_j^{(k+1)} - \sum_{j=i+1}^n a_{ij}x_j^{(k)}\right)
$$
**Convergence Criteria:** Diagonal dominance  
**Files:**  
`GAUSS_SEIDAL.C` | `GAUSS_SEIDAL_INTERMEDIATE.C` | `GAUSS_SEIDAL_ADVANCED.C`

## 🛠 Usage Example
```c
#include "lineqsolvers.h"

int main() {
    double A[3][3] = {{4, 1, -1}, {2, 7, 1}, {1, -3, 12}};
    double b[3] = {3, 19, 31};
    double x[3];
    int n = 3, max_iter = 100;
    double tol = 1e-6;

    gauss_elimination(n, A, b, x);  // Direct method
    // OR
    gauss_seidel(n, A, b, x, max_iter, tol);  // Iterative method

    printf("Solution: [%.6f, %.6f, %.6f]\n", x[0], x[1], x[2]);
    return 0;
}
```

## 📊 Method Comparison

| Method            | Type      | Complexity | Stability       | Best For                |
|-------------------|-----------|------------|-----------------|-------------------------|
| Gaussian Elimination | Direct   | O(n³)      | Partial Pivoting | Small/medium systems    |
| Gauss-Seidel      | Iterative | O(n²)/iter | Diagonal Dominant| Large sparse systems    |

## 📁 File Structure

```
linear-equations/
├── Gaussian_Elimination/
│   ├── GAUSS_ELIMINATION_BEG.C     // Basic implementation
│   └── GAUSS_ELIMINATION_ADV.C     // With partial pivoting
└── Gauss_Seidel/
    ├── GAUSS_SEIDAL.C              // Basic implementation
    ├── GAUSS_SEIDAL_INTERMEDIATE.C // Optimized version
    └── GAUSS_SEIDAL_ADVANCED.C     // With relaxation parameter
```

## 📝 Theoretical Notes

**Pivoting Strategies:**
- Partial pivoting: Prevents division by zero
- Full pivoting: Better numerical stability

**Convergence Analysis:**
- Gauss-Seidel converges if either:
  - Matrix is strictly diagonally dominant, or
  - Matrix is symmetric positive definite

**Residual Calculation:**
$$
\|r\| = \|b - Ax\|
$$

## 📚 References

1. Golub & Van Loan (2013), *Matrix Computations*
2. Trefethen & Bau (1997), *Numerical Linear Algebra*
3. Saad (2003), *Iterative Methods for Sparse Linear Systems*

<div align="center">
  <img src="https://render.githubusercontent.com/render/math?math=\color{blue}\boxed{Ax=b\ \Rightarrow\ x=A^{-1}b}" alt="Linear Equation Solution">
</div>
