# 🧙‍♂️⚔️ CC3k

CC3k is a roguelike, dungeon-crawling game developed in C++ that immerses players in a turn-based combat adventure. The game uses core object-oriented programming (OOP) principles to create race-specific character behaviors and dynamic dungeon mechanics. With a modular architecture built on the Factory and Observer design patterns, CC3k provides a scalable and engaging gameplay experience.

## 🌟💡 Inspiration

The inspiration behind CC3k came from classic roguelike games that emphasize strategic combat, exploration, and randomness. The goal was to build an object-oriented C++ application that not only highlights solid software design principles but also offers an engaging gameplay loop with replay value. By implementing design patterns and effective memory management, CC3k achieves modularity and robustness, making it easy to extend or enhance.

## 🕹️📋 How It Works

### 👤 Character Classes
- 🧝‍♀️ **Race-Specific Characters**: Choose from a variety of races, each with unique behaviors and stats (e.g., Elf, Dwarf, Human).
- ♻️ Uses inheritance and polymorphism to define custom race logic while sharing common functionality via base classes.

### 🧟 Combat System
- 🎲 **Turn-Based System**: Players and enemies alternate turns to attack, defend, or use items.
- ⚔️ **Probabilistic Attacks**: Combat includes chance mechanics to simulate hit/miss/damage variability.
- 💀 Enemies spawn dynamically and patrol the dungeon.

### 🧱 Dungeon Mechanics
- Procedurally loaded dungeon floors with items, enemies, and obstacles.
- 🏭 **Factory Pattern**: Used to efficiently create game entities like characters, potions, and enemies.
- 👁️ **Observer Pattern**: Keeps the UI or event systems in sync with changes in the game state (e.g., health updates, movements).

## 🧠 Technologies Used

- 🧾 **C++**: Core language used to implement game logic, rendering, and memory management.
- 📦 **OOP Concepts**: Inheritance, polymorphism, encapsulation to organize and extend game behavior.
- 🔁 **Design Patterns**:
  - **Factory** – For flexible and extensible object creation.
  - **Observer** – For decoupled event handling and real-time updates.
- 🔄 **RAII** and smart pointers: To ensure safe and efficient memory handling.

## 🏆🎉 Accomplishments That We Are Proud Of

- 🔧 Object-oriented architecture enabling clean, reusable code.
- ⚔️ Balanced combat system using randomization and strategy.
- 🧱 Dynamic dungeon interaction and entity spawning.
- 🔁 Scalable design patterns for easy feature expansion.
- 🧹 Manual and smart memory management for stable runtime.

## 🔮🚀 What's Next for CC3k

- 🧭 **Procedural Dungeon Generation**: Create random layouts for every run.
- 💬 **Story Events and Lore**: Introduce NPCs, dialogue, and world-building.
- 🖼️ **Graphical Interface**: Add a simple SDL/GUI layer for richer visuals.
- 🎮 **Game Saving/Loading**: Persistent state for continued play sessions.
- 🧪 **Unit Tests**: Build test coverage around core mechanics.


## 🚀 Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`)
- `make` utility

### Installation

1. Clone the repository:

```bash
git clone https://github.com/Blank9999/CC3k.git
cd CC3k
```

2. Build the project:

```bash
make
```

3. Run the executable:

```bash
./exec
```

### 🙏 Acknowledgments

- Thanks to Praay, Blank9999 and MaxChung525.
- Thanks to the C++ community and open-source developers for best practices and design pattern references.
