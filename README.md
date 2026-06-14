# 🐍 Classic Snake Game

A terminal-based Snake game built in **C++** with difficulty levels, real-time keyboard controls, score tracking, and a persistent high score system — all rendered in the Windows console.

---

## 📸 Screenshots

### Difficulty Selection
![Difficulty Selection](photos/photo_2_2023-02-25_21-20-48.jpg)

### Gameplay
![Gameplay](photos/photo_1_2023-02-25_21-20-48.jpg)

### Game Over Screen
![Game Over](photos/photo_3_2023-02-25_21-20-48.jpg)

---

## 🎮 Features

- **3 Difficulty Levels** — Easy, Medium, and Hard (controls snake speed)
- **Real-time Controls** — Move using `W A S D` keys, pause with `Space`
- **Score System** — Earn 10 points per food eaten
- **High Score Tracking** — Persists across rounds in the same session
- **Game Over Screen** — Shows your score vs high score with restart option
- **Console Rendering** — Smooth rendering using Windows Console API

---

## 🕹️ Controls

| Key | Action |
|-----|--------|
| `W` | Move Up |
| `A` | Move Left |
| `S` | Move Down |
| `D` | Move Right |
| `Space` | Pause / Stop |

---

## 🚀 Getting Started

### Prerequisites

- Windows OS (uses `<windows.h>`, `<conio.h>`)
- C++ compiler — [MinGW](https://www.mingw-w64.org/) or [Dev-C++](https://www.bloodshed.net/)

### Build & Run

```bash
# Clone the repo
git clone https://github.com/adityaraj152002/Classic-Snake-Game.git
cd Classic-Snake-Game

# Compile
g++ main.cpp -o snake

# Run
./snake
```

Or open `new snake.layout` directly in **Dev-C++** and hit Run.

---

## 📁 Project Structure

```
Classic-Snake-Game/
├── main.cpp                        # Core game logic
├── new snake.cpp                   # Alternate/dev version
├── new snake.depend                # Dev-C++ dependency file
├── new snake.layout                # Dev-C++ project layout
└── photos/                         # Screenshots of the game
```

---

## 🧠 How It Works

The game uses a class-based OOP structure in C++:

| Method | Description |
|--------|-------------|
| `set_value()` | Initializes snake position, food, and score |
| `design()` | Renders the game board to the console each frame |
| `input()` | Captures non-blocking keypresses via `_kbhit()` and `_getch()` |
| `control()` | Updates snake head coordinates based on direction |
| `length()` | Shifts tail segments to follow the head |
| `Score()` | Detects food collision, increments score, spawns new food |
| `GameOver()` | Displays end screen with final score and high score |

---

## 👥 Team

Built as a college group project:

| Name | Contribution |
|------|-------------|
| Adityaraj Patil | Movement control logic |
| Pranav Patil | Keyboard input handling |
| Yash Salunke | Game initialization |
| Karteek Patil | Main game loop |

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
