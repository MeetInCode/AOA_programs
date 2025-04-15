# Algorithm Analysis Programs

This repository contains implementations of various graph algorithms in C. Each implementation is designed to be clear, efficient, and educational.

## Algorithms Included

1. **Bellman-Ford Algorithm** (`bellmanford.c`)

   - Single-source shortest path algorithm
   - Handles negative weight edges
   - Time Complexity: O(VE)

2. **Dijkstra's Algorithm** (`Dijkstra.c`)

   - Single-source shortest path algorithm for non-negative weights
   - Uses adjacency matrix representation
   - Time Complexity: O(V²)

3. **Floyd-Warshall Algorithm** (`floydwarshall.c`)

   - All-pairs shortest path algorithm
   - Works with positive and negative edge weights
   - Time Complexity: O(V³)

4. **Kruskal's Algorithm** (`kruskal.c`)

   - Minimum Spanning Tree algorithm
   - Uses Union-Find data structure
   - Time Complexity: O(E log E)

5. **Prim's Algorithm** (`prims.c`)
   - Minimum Spanning Tree algorithm
   - Uses adjacency matrix representation
   - Time Complexity: O(V²)

## How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/MeetInCode/AOA_programs.git
   ```

2. Compile any program using gcc:

   ```bash
   gcc -o program_name program_name.c
   ```

3. Run the compiled program:
   ```bash
   ./program_name
   ```

## Requirements

- GCC compiler
- C standard library

## Contributing

Feel free to contribute to this repository by:

1. Forking the project
2. Creating your feature branch
3. Committing your changes
4. Pushing to the branch
5. Opening a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details.
