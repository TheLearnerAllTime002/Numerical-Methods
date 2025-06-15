
# ➗ Linear Equation Solvers

> High-performance C implementations of direct and iterative methods for solving systems of linear equations (Ax = b) with numerical stability analysis.

<div align="center">
  <img src="https://img.shields.io/badge/C-99%20Standard-blue?logo=c" alt="C Standard">
  <img src="https://img.shields.io/badge/Methods-4-brightgreen" alt="Method Count">
  <img src="https://img.shields.io/badge/Precision-Double-important" alt="Precision">
  <img src="https://img.shields.io/badge/License-MIT-success" alt="License">
</div>



**Files:**  
`GAUSS_SEIDAL.C` | `GAUSS_SEIDAL_INTERMEDIATE.C` | `GAUSS_SEIDAL_ADVANCED.C`

## 🛠 Usage Examples

### Gaussian Elimination
```c
#include "gauss_elim.h"

int main() {
    double A[3][3] = {{4, 1, -1}, {2, 7, 1}, {1, -3, 12}};
    double b[3] = {3, 19, 31};
    double x[3];
    
    gauss_eliminate(3, A, b, x, 1);  // Last arg enables pivoting
    
    printf("Solution: [%.8f, %.8f, %.8f]\n", x[0], x[1], x[2]);
    return 0;
}
```

### Gauss-Seidel Iteration
```c
#include "gauss_seidel.h"

int main() {
    double A[3][3] = {{4, 1, -1}, {2, 7, 1}, {1, -3, 12}};
    double b[3] = {3, 19, 31};
    double x[3] = {0};  // Initial guess
    double tol = 1e-9;
    int max_iter = 1000;
    
    int iter = gauss_seidel(3, A, b, x, tol, max_iter);
    
    printf("Converged in %d iterations\nSolution: [%.8f, %.8f, %.8f]\n", 
           iter, x[0], x[1], x[2]);
    return 0;
}
```

## 📊 Performance Comparison

| Method               | Type       | Complexity  | Stability         | Best Case Scenario          |
|----------------------|------------|-------------|-------------------|-----------------------------|
| Gaussian Elimination | Direct     | O(n³)       | Moderate          | Dense systems < 1000 eqns   |
| Gauss-Seidel         | Iterative  | O(n²)/iter  | High (if DD)      | Sparse, diagonally dominant |

**Key:**
- DD = Diagonally Dominant
- iter = per iteration

## 📁 Repository Structure

```
linear-solvers/
├── gauss_elim/
│   ├── GAUSS_ELIMINATION_BEG.C    # Basic version
│   └── GAUSS_ELIMINATION_ADV.C    # With partial pivoting
├── gauss_seidel/
│   ├── GAUSS_SEIDAL.C             # Basic implementation
│   ├── GAUSS_SEIDAL_INTERMEDIATE.C# Optimized version
│   └── GAUSS_SEIDAL_ADVANCED.C    # With relaxation parameter
├── include/
│   ├── gauss_elim.h               # Header for GE
│   └── gauss_seidel.h             # Header for GS
└── examples/
    ├── basic_ge.c                 # Usage example
    └── basic_gs.c                 # Usage example
```

## 📝 Theoretical Background

### Gaussian Elimination
- **Pivoting Strategy:** Partial pivoting prevents division by zero and reduces round-off errors
- **Operation Count:** ≈⅔n³ + O(n²) FLOPs
- **Condition Number:** κ(A) affects numerical stability

### Gauss-Seidel
- **Convergence Theorem:** Guaranteed if A is strictly diagonally dominant
- **Error Reduction:** Linear convergence rate
- **Acceleration:** Successive Over-Relaxation (SOR) variant available

## 📚 References

1. Golub & Van Loan (2013), *Matrix Computations* (4th Ed.)
2. Saad (2003), *Iterative Methods for Sparse Linear Systems* (2nd Ed.)
3. Demmel (1997), *Applied Numerical Linear Algebra*

