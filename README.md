# Minesweeper Game
This project finds safe bike paths in a national park modeled as interconnected hexagonal chambers. The program identifies a path from the park entrance to all treasure chambers while avoiding sealed or dark chambers. The algorithm prioritizes treasure and lighted chambers for safety and optimal exploration.

## Project Images
![Minesweeper image](minesweeperEx.png)

## **Key Features**

- **Minesweeper Board**  
  16x30 grid with 99 mines, matching the traditional expert difficulty.

- **Safe First Click**  
  Ensures the first tile clicked is never a mine.

- **Right-Click Marking System**  
  Toggle through:
  - 🚩 Flag  
  - ❓ Question mark  
  - Empty

- **Recursive Reveal of Empty Spaces**  
  Automatically uncovers adjacent safe tiles with zero neighboring mines.

- **Game Reset and Win/Lose Messages**  
  Restart the game after finishing — with prompt dialogs and clean board reset.
---

## **Technologies Used**

- **C++11** – Core logic and object-oriented design  
- **Qt (Widgets Module)** – GUI development and layout management  
- **QPushButton Customization** – For interactive grid buttons  
- **Qt Resource System (`.qrc`)** – For bundling icons and images

---

## How to Run

### Prerequisites:
- Qt 5 or 6 installed
- C++ compiler (e.g., g++, clang++)
- Qt Creator or command-line `qmake`/`make`

### Build & Run (with Qt Creator):
1. Open `minesweeper.pro` in **Qt Creator**
2. Configure the kit (GCC, Clang, MSVC, etc.)
3. Click **Run**

### Command-Line (Linux/macOS):
```bash
qmake
make
./Minesweeper
