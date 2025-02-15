# 🐬 so_long


 Technologies Used
 Table of Contents
 Installation
🎮 Usage
 Libxkit
 Controls
 Contributing
 Acknowledgments

## 📝 Description
**so_long** is a 2D game developed as part of the 42 curriculum, utilizing the **MinilibX** graphical library. The project expands on the standard implementation by incorporating **Libxkit**, a custom-built library that acts as a small game engine, providing additional tools and abstractions over MinilibX.

The game features multiple levels, each represented with unique assets. The player must collect all collectibles before reaching the exit to progress. To enhance the gameplay experience, the game dynamically changes **assets and environment** as the player collects a certain percentage of items. The levels included are:
- **Basic Level**  
- **Ice Level** ❄️  
- **Desert Level** 🏜️  
- **Pac-Man Inspired Level** 🟡  
- **Mario Inspired Level** 🍄  

All **sprites** used in the game were drawn by myself (badly).

![image](https://github.com/user-attachments/assets/3347c713-3f70-419f-91b2-361bd5ebe3f4)
![image](https://github.com/user-attachments/assets/ad5fcaaa-b83d-438e-8514-3b48734a3079)
![image](https://github.com/user-attachments/assets/1df50659-03d6-4b05-b380-aaf74fb71f69)
![image](https://github.com/user-attachments/assets/15ab02ed-2721-499f-9d6c-9c2a9e453ea7)
![image](https://github.com/user-attachments/assets/97afbe2b-3cc7-41dd-bdec-b851d78248a1)

## 🛠️ Technologies Used
- **C**
- **Vim**
- **MinilibX (MLX)**
- **LIBXKIT (Custom Game Toolkit built on MinilibX)**
- **Valgrind** (a lot)

## 📖 Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Game Features](#game-features)
- [Libxkit - A Custom Game Toolkit](#libxkit---a-custom-game-toolkit)
- [Controls](#controls)
- [Contributing](#contributing)
- [Acknowledgments](#acknowledgments)

## 📥 Installation
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

## 🕹️ Usage
The goal of the game is simple: collect all the collectibles (`C`) on the map before reaching the exit (`E`).

## 🎮 Game Features
🏞 **Multiple Themed Levels:** The game dynamically swaps textures and sprites to transform the environment.
🖌️ **Custom Sprites:** All graphics were hand-drawn, making the game unique and visually distinct.
🎥 **Camera System:** The player remains centered while moving through larger maps.
👿 **(Very) Basic Enemy AI:** Simple enemy movement and collision detection.
⚡ **Performance Optimizations:** Implemented frame rate control to minimize flickering.
🔍 **Error and Memory Handling:** I hope you can find some possible failure scenarios or leaks I may have missed! 😅

## 🖥️ Libxkit - A Custom Game Toolkit
**Libxkit** is a set of utility functions built on top of MinilibX to **simplify** and **enhance** game development:By developing this library, this project goes beyond just using MinilibX — it builds a foundational **game framework** for future graphical projects.

### 🚀 Features

#### 🔷 🎨 Rendering & Graphics
🏞 **Background rendering** (render_background)
🏛 **Tile-based map rendering** (render_map, rm_put_tiles)
👾 **Character rendering** (render_hero, render_enemy)
🎨 **Pixel manipulation** (mlx_fast_pixel_put)
✏️ **Basic drawing utilities** (draw_mlx_line, draw_mlx_circle, draw_mlx_rect)

#### 🎮 🕹️ Game Mechanics & Interaction
🎥 **Camera movement & bounds checking** (set_cam, update_cam_pos, center_cam_on_hero)
🚶‍♂️ **Character movement & animation** (on_motion_up, on_motion_down, move_to_left, move_to_right)
🔍 **Collision detection** (check_collision_tile, check_collision_radius)
🖥 **Game UI rendering** (display_steps_on_screen, display_steps_on_terminal)

#### 🗺️ 🛠️ Map & Level Management
📜 **Map parsing & validation** (map_validator, check_border, count_chars)
🔄 **Dynamic level loading** (load_paths, upload_assets)
🔍 **Flood-fill pathfinding for validation** (flood_count, flood_count_left, flood_count_right)

#### 🏗️ 🛡️ Game State & Memory Management
🎬 **Game state initialization** (init_state, set_state, set_window, set_hooks)
🗑️ **Resource management & cleanup** (sl_memfree, sl_destroy_imgs, free_paths)
🎭 **Dynamic asset loading** (load_paths_tiles, load_paths_hero, load_paths_enemy)

## 🎮 Controls
| Key         | Action |
|------------|--------|
| `W` / `↑`  | Move Up |
| `S` / `↓`  | Move Down |
| `A` / `←`  | Move Left |
| `D` / `→`  | Move Right |
| `ESC`      | Exit the Game |

## 🤝 Contributing
If you'd like to contribute or suggest improvements, feel free to:
- **Fork the repository**
- **Create a new branch** (`git checkout -b feature-branch`)
- **Make your changes** and commit (`git commit -am "Add new feature"`)
- **Push to your branch** (`git push origin feature-branch`)
- **Open a Pull Request**

## 💙 Acknowledgments
- **42 Network** for the opportunity to work on this project.
- The **MinilibX creators** for providing the core graphical library.
- [Bra1nOut](https://github.com/Bra1nOut) for the idea of a percentage system.

