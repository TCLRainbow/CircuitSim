# CircuitSim

## `CIRCUITSIM_PRECISION` macro
You can simulate your circuit at different levels, each level would simulate the details of that component.  
For example, at level 0, invoking `pmos()` would simulate
how the source, drain and gate works, whereas level 1 would just return the inversion of the input.

0. Transistor level: Simulates source, drain and gate
1. Logic Gate level: Simulates connecting MOSFETs