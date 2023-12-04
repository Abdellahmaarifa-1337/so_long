# So Long And Thanks For All The Fish!

## Introduction

The "So Long" project is a small 2D game aimed at improving skills in computer graphics, utilizing textures, sprites, and basic gameplay elements. The game involves creating an environment where the player, represented by a character, collects items and escapes. The project utilizes the MiniLibX library for graphical interactions.

## Objectives

This project focuses on enhancing skills in window management, event handling, colors, textures, and more. It introduces the MiniLibX library, providing essential tools for window creation, image handling, and keyboard/mouse event management.

## Mandatory Part

### Program Details

- Program Name: so_long
- Files: Makefile, _.h, _.c, maps, textures
- Makefile: NAME, all, clean, fclean, re
- Arguments: A map in the format \*.ber
- External Functions: open, close, read, write, malloc, free, perror, strerror, exit, math library functions, MiniLibX functions, ft_printf or equivalent

### Game Mechanics

- The player's goal is to collect all collectibles and escape with the shortest route.
- Use W, A, S, and D keys for character movement.
- Movement in 4 directions: up, down, left, right.
- Player cannot move into walls.
- Display the current number of movements in the shell after each move.
- Utilize a 2D view (top-down or profile).
- Game doesn't have to be real-time.

### Graphic Management

- Display the image in a window using MiniLibX.
- Ensure smooth window management.
- Pressing ESC or clicking the window's close button must quit the program cleanly.

### Map

- Map components: walls, collectibles, free space, exit, player's starting position.
- Map characters: 0 (empty space), 1 (wall), C (collectible), E (map exit), P (player's starting position).
- Validate map:
  - Must have 1 exit, at least 1 collectible, and 1 starting position.
  - No duplicate characters for exit or starting position.
  - Must be rectangular.
  - Must be closed/surrounded by walls.

### Example Map

```plaintext
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
