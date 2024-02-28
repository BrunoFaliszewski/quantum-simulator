
# Quantum Simulator

Quantum simulator is C++ library that allows you to make your own quantum circuits and see probabilities of final results.

## Example

This is example of simple quantum circuit that entangles 2 qubits.

```cpp
#include "QuantumComputer.h"

using namespace std;

int main() {
    QuantumComputer q = QuantumComputer(2);
    q.LO(q.hadamar, 0);
    q.LO(q.CX, 0);
    q.probability();

    return 0;
}
```

#### Output

```
00 - 50%
11 - 50%
```

## Documentation

### QuantumComputer

#### Initialization:

```cpp
QuantumComputer(int number_of_qubits)
```

#### Parameters:

```cpp
int qubits; // number of qubits in a circuit
Matrix state; // state of all qubits together
```

#### Functions:

```cpp
void LN(Matrix m, int qubit); // apply Matrix m operation on int qubit
void probability(); // print out probabilities of collapsing to certain states
```

This convention of showing probabilities is different to one that IBM uses. Here qubit number 1 is the first shown in probabilities. IBM for some reason shows qubit number 1 as the last one which leads to different probabilities, because linear operations are applied in different order.

#### Operations:

hadamar:
```
| 1  1 | / sqrt(2)
| 1 -1 | / sqrt(2)
```

pauliX:
```
| 0 1 |
| 1 0 |
```

pauliY:
```
| 0 -i |
| i  0 |
```

pauliZ:
```
| 1  0 |
| 0 -1 |
```

CX:
```
| 1 0 0 0 |
| 0 1 0 0 |
| 0 0 0 1 |
| 0 0 1 0 |
```

CZ:
```
| 1 0 0  0 |
| 0 1 0  0 |
| 0 0 1  0 |
| 0 0 0 -1 |
```

SWAP:
```
| 1 0 0 0 |
| 0 0 1 0 |
| 0 1 0 0 |
| 0 0 0 1 |
```

CCX:
```
| 1 0 0 0 0 0 0 0 |
| 0 1 0 0 0 0 0 0 |
| 0 0 1 0 0 0 0 0 |
| 0 0 0 1 0 0 0 0 |
| 0 0 0 0 1 0 0 0 |
| 0 0 0 0 0 1 0 0 |
| 0 0 0 0 0 0 0 1 |
| 0 0 0 0 0 0 1 0 |
```

You can also use your custom matrices