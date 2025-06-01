# 🚢 Battleship Game (C++ Console Version)

A classic Battleship game implemented in C++ using terminal-based interaction. Challenge the CPU or a friend in a strategic game of naval warfare! Ships are placed either manually or randomly, and the game proceeds turn-by-turn until one side sinks all of the opponent's ships.

---

##  Features

-  Text-based UI with clear instructions and feedback
-  **Score system**: Tracks hits and determines the winner
-  **Single Player Mode** – Play against a CPU with random attacks
- **Multiplayer Mode** – Two players can manually place and attack ships
- Realistic ship placement rules (cannot overlap or go out-of-bounds)
- Matrix representation of ship positions and attacks
- **Prevents repeated attacks** on the same location
- Visual feedback using:
  - `*` for unexplored cells
  - `S` for ships (hidden from opponent)
  - `O` for successful hits
  - `X` for misses

---

## 🗺 Game Board

- Grid size: **7 rows x 9 columns**
- Ships: 5 ships with sizes `2, 3, 3, 4, 5`
- Player inputs coordinates as `(row column)` to attack

