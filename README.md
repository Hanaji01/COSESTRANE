# COSESTRANE

**COSESTRANE** is a terminal-based adventure and combat game developed in **C** as the final project for the **Procedural Programming** course at the **University of Perugia (UniPG)**.

The game combines exploration, turn-based combat, random map generation, item management, and multiple game worlds.

---

## Description

In **COSESTRANE**, players explore a randomly generated map divided into two interconnected worlds:

* **Mondo Reale (Real World)**
* **Soprasotto**

Players must move through different areas, collect useful objects, fight enemies, and use portals to travel between the two worlds.

The game supports **1 to 4 players** and is entirely played through the terminal.

---

## Objective

The main goal is to explore the game world, survive encounters with enemies, and reach the final challenge represented by the **Demotorzone**.

Players must carefully manage their health, items, movements, and combat actions in order to progress through the game.

---

## Game Worlds

### Mondo Reale

The Real World contains several different types of areas, including:

* Forest
* School
* Laboratory
* Cave
* Road
* Garden
* Supermarket
* Power Plant
* Abandoned Warehouse
* Police Station

### Soprasotto

The Soprasotto is the second world of the game and contains enemies, objects, and the final challenge.

The map is randomly generated at the beginning of each game.

A **Demotorzone** is generated in the Soprasotto and represents the final enemy of the game.

---

## Players

The game supports from **1 to 4 players**.

At the beginning of the game, players are created and assigned their starting statistics.

The turn order is randomly determined at the beginning of each round.

---

## Combat System

Combat is **turn-based** and uses a **20-sided die (d20)** to determine attack outcomes.

When facing an enemy, players can choose between different actions:

1. **Basic Attack**
2. **Powered Attack**
3. **Defense**
4. **Use an Item**

The **Powered Attack** consumes player HP but allows the player to deal increased damage.

The **Defense** action temporarily increases the player's defensive capability for the current turn.

---

## Enemies

The game features three types of enemies:

| Enemy           | Description                                           |
| --------------- | ----------------------------------------------------- |
| **Billi**       | A regular enemy encountered during exploration        |
| **Democane**    | A stronger enemy that can block the player's progress |
| **Demotorzone** | The final enemy of the Soprasotto                     |

Enemies can prevent players from progressing through certain areas until they are defeated.

---

## Items

Players can find and collect different objects throughout the map.

The available items include:

* **Bicicletta**
* **Maglietta Fuocoinferno**
* **Bussola**
* **Schitarrata Metallica**

Items can be collected and stored in the player's backpack.

During the game, players can choose to use an item directly from their inventory.

---

## Movement

During each turn, a player can perform one movement action.

Available movement options include:

* **Move forward** to the next area
* **Move backward** to the previous area
* **Change world** through a portal
* **Pass the turn**

Movement can be affected by the presence of enemies in the current area.

---

## Portals

The two worlds are connected through portals.

Players can travel between **Mondo Reale** and **Soprasotto**, but the rules for crossing depend on the direction of travel and the current situation.

When attempting to return from the Soprasotto to the Real World, the player must perform a **fortune roll** and compare the result with their fortune value.

---

## Available Actions

During a turn, players can choose from several actions:

```text
1. Move to the next area
2. Move to the previous area
3. Change world
4. Fight an enemy
5. View player statistics
6. View current area
7. Collect an item
8. Use an item from the backpack
9. Pass the turn
```

---

## Game Progress

The game combines:

* Exploration
* Random map generation
* Enemy encounters
* Turn-based combat
* Item collection
* Inventory management
* World transitions
* Random dice rolls
* Multiple players

The objective is to progress through the generated map and overcome the challenges encountered along the way.

---

## Technical Structure

The project is organized into three main files:

```text
COSESTRANE/
│
├── main.c
├── gamelib.c
├── gamelib.h
└── README.md
```

### `main.c`

Contains the entry point of the program and starts the game.

### `gamelib.h`

Contains the declarations, data structures, enumerations, and function prototypes used by the game.

### `gamelib.c`

Contains the main implementation of the game, including:

* Map generation
* Player management
* Enemy management
* Object management
* Movement
* Combat
* World transitions
* Game statistics
* Memory management
* Credits

---

## Programming Concepts

The project was developed to apply the concepts studied during the **Procedural Programming** course.

The main concepts used include:

* **C programming**
* **Structures (`struct`)**
* **Enumerations (`enum`)**
* **Pointers**
* **Dynamic memory allocation**
* **Linked structures**
* **Functions**
* **Modular programming**
* **Random number generation**
* **Input handling**
* **Memory deallocation**
* **Header files**
* **Source files**

Dynamic memory is managed using `malloc()` and released using `free()`.

The game map is implemented through linked structures and pointers, allowing the program to dynamically create and connect different areas.

---

## Random Generation

Several game elements are generated randomly, including:

* Map configuration
* Enemies
* Objects
* Dice results
* Player turn order

This makes each game session different from the previous one.

---

## Game Statistics

The game keeps track of the number of games played and stores information about the **last three winners**.

This information can be displayed through the game's **Credits** section.

---

## Compilation

To compile the project using GCC:

```bash
gcc main.c gamelib.c -o COSESTRANE
```

Then run the executable.

### Linux / macOS

```bash
./COSESTRANE
```

### Windows

```bash
COSESTRANE.exe
```

---

## University Project

This project was developed as the **final project for the Procedural Programming course** of the **Computer Science degree at the University of Perugia**.

**Academic Year:** 2025/2026

---

## Author

**Hanaji Tancre'**

Computer Science — University of Perugia

---

## License

This project is released under the **MIT License**.
