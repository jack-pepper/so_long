# so_long

## Description
**so_long** is a 2D game developed as part of the 42 curriculum, utilizing the **MinilibX** graphical library. The project expands on the standard implementation by incorporating **Libxkit**, a custom-built library that acts as a small game engine, providing additional tools and abstractions over MinilibX.

The game features multiple levels, each represented with unique assets. The player must collect all collectibles before reaching the exit to progress. To enhance the gameplay experience, the game dynamically changes **assets and environment** as the player collects a certain percentage of items. The levels included are:
- **Basic Level**  
- **Ice Level** ❄️  
- **Desert Level** 🏜️  
- **Pac-Man Inspired Level** 🟡  
- **Mario Inspired Level** 🍄  

All **sprites** used in the game were drawn by myself (badly).

## Technologies Used
- **C**
- **MinilibX (MLX)**
- **LIBXKIT (Custom Game Toolkit built on MinilibX)**
- **Valgrind** (a lot)

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Game Features](#game-features)
- [Libxkit - A Custom Game Toolkit](#libxkit---a-custom-game-toolkit)
- [Controls](#controls)
- [Contributing](#contributing)
- [Acknowledgments](#acknowledgments)

## Installation
To set up and run the project locally, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/pepper/so_long.git
   cd so_long
   ```

2. **Compile the project:**
   ```bash
   make bonus
   ```

3. **Run the game:**
   ```bash
   ./so_long maps/valid_map_so_long_bonus.ber
   ```

## Usage
The goal of the game is simple: collect all the collectibles (`C`) on the map before reaching the exit (`E`).

## Game Features
- **Multiple Themed Levels:** The game dynamically swaps textures and sprites to transform the environment.
- **Custom Sprites:** All graphics were hand-drawn, making the game unique and visually distinct.
- **Camera System:** The player remains centered while moving through larger maps.
- **Basic Enemies handling:** Simple enemy movement and collision detection.
- **Performance Optimizations:** Implemented **frame rate control** to minimize flickering.
- **Error and Memory Handling:** I hope you can find some possible failure scenarii or leak I may have missed!

## Libxkit - A Custom Game Toolkit
**Libxkit** is a set of utility functions built on top of MinilibX to **simplify** and **enhance** game development:
- **Sprite Management:** Handles animations by sprites swapping and directional movement.
- **Custom Rendering Functions:** Provides optimized drawing functions for improved performance.

By developing **Libxkit**, this project goes beyond just using MinilibX — it builds a foundational **game framework** for future graphical projects.

## Controls
| Key         | Action |
|------------|--------|
| `W` / `↑`  | Move Up |
| `S` / `↓`  | Move Down |
| `A` / `←`  | Move Left |
| `D` / `→`  | Move Right |
| `ESC`      | Exit the Game |

## Contributing
If you'd like to contribute or suggest improvements, feel free to:
- **Fork the repository**
- **Create a new branch** (`git checkout -b feature-branch`)
- **Make your changes** and commit (`git commit -am "Add new feature"`)
- **Push to your branch** (`git push origin feature-branch`)
- **Open a Pull Request**

## Acknowledgments
- **42 Network** for the opportunity to work on this project.
- The **MinilibX creators** for providing the core graphical library.
- [Bra1nOut](https://github.com/Bra1nOut) for the idea of a percentage system.

