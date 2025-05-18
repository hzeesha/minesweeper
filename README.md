# Minesweeper Game
This project finds safe bike paths in a national park modeled as interconnected hexagonal chambers. The program identifies a path from the park entrance to all treasure chambers while avoiding sealed or dark chambers. The algorithm prioritizes treasure and lighted chambers for safety and optimal exploration.

## Project Images
![Minesweeper image](minesweeperEx.png)

## **Key Features**
- **Implemented a Custom Stack (DLStack)**:
  - Built using a doubly linked list.
  - Supports advanced operations like removing the k-th element.
- **Pathfinding Algorithm**:
  - Traverses the map to find paths from the entrance to all treasure chambers.
  - Follows strict prioritization rules:
    1. Treasure chambers over others.
    2. Lighted chambers over dim chambers.
  - Avoids sealed and dark chambers.

## **Technologies**
- **Java**: Core implementation.
- **Custom Data Structures**: Doubly linked list and extended stack.

## **Results**
- Successfully computed valid paths while visualizing the traversal process.
- Ensured compliance with constraints like prioritizing treasure and lighted chambers.
- Verified functionality using provided test cases and additional scenarios.

## **Challenges**
- Designing a flexible stack capable of advanced operations.
- Efficiently handling chamber prioritization in pathfinding.

## **Execution**
To run the program:
1. Navigate to the project root directory.
2. Run the following commands:
   ```bash
   javac src/*.java
   java -cp src Pyramid map1.txt
There are 5 tester maps. So, mapx.txt will change the map
