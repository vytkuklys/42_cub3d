# cub3D
## My first RayCaster with miniLibX.
This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever.<br>
It will enable you to explore ray-casting.<br>
Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.<br>
## from [vytkuklys](https://github.com/vytkuklys) and [tblaase](https://github.com/tblaase)<br>
<!-- ![result](https://github.com/vytkuklys/42_cub3d/blob/main/readme_additions/minishell_result.jpg) -->
## Contents
- [Short description](https://github.com/vytkuklys/42_cub3d/new/main?readme=1#short-description-of-the-project)
- [Our cub3D](https://github.com/vytkuklys/42_cub3d/new/main?readme=1#our-cub3d)
  - [Requirements to run the game](https://github.com/vytkuklys/42_cub3d/new/main?readme=1#requirements-to-run-the-game)
  - [How to cub3D](https://github.com/vytkuklys/42_cub3d/new/main?readme=1#how-to-cub3d)
  - [Map requirements](https://github.com/vytkuklys/42_cub3d/new/main?readme=1#map-requirements)
- [Example](https://github.com/vytkuklys/42_cub3d/new/main?readme=1#example)

## Short description of the project

This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.<br><br>
As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.<br><br>
To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.<br><br>
With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.<br><br>
For the detailed instructions on the project, [here](https://github.com/vytkuklys/42_cub3d/blob/main/readme_additions/en.subject.pdf) is the subject.pdf.<br>

## Our cub3D
### Requirements to run the game
only tested on **macOS Catalina (Version 10.15.7)**<br>
For all other OS it is not guaranteed to work.<br>
OpenGL and AppKit is required to run it.<br>
If you want to run it on Linux [here](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux) is a tutorial that might help and [here](https://github.com/42Paris/minilibx-linux) is the required verion of miniLibX.<br>
### How to cub3D
1. run `make` or `make all` in the root of the directory
2. run `./cub3D maps/42.cub` in the root of the directory
3. move the character with `WASD`
4. turn the FOV left and right by pressing `arrow_left` and `arrow_right` or by moving the mouse right or left
Things to enjoy
- wall collition
- moving hands while walking
- opening and closing doors by walking into them
- fully customizable [maps](https://github.com/vytkuklys/42_cub3d/tree/main/maps)

[back to **Our cub3D**](https://github.com/vytkuklys/42_cub3d/new/main?readme=1#our-cub3d)<br>
[back to **Contents**](https://github.com/vytkuklys/42_cub3d/new/main?readme=1#contents)<br>

### Map requirements
- decide which texture is displayed on which side
- `0` define walkable spaces
- `1` define walls
- `2` define doors
- the players position is displayed by:
  - `N` player is facing north (top of the 2D map)
  - `E` player is facing east (right side of the 2D map)
  - `S` player is facing south (bottom of the 2D map)
  - `W` player us facing west (left side of the 2D map)
- the map has to be enclosed by walls on all sides
- doors have to have walls on two opposite sides
- any other characters other than the ones above are forbidden
- if there is a ` `(space)&nbsp;inside the map it has to be enclosed by walls
- only one player position is allowed
- you have to set all the textures that should be used as wall texture i.e.
  - `WE images/1.xpm`
  - `EA images/2.xpm`
  - `SO images/3.xpm`
  - `NO images/4.xpm`
- you have to set the ceiling color, i.e.:
  - `C 0, 183, 183`
- you have to set the floor color, i.e.:
  - `F 141, 1, 126`

[back to **Our cub3D**](https://github.com/vytkuklys/42_cub3d/new/main?readme=1#our-cub3d)<br>
[back to **Contents**](https://github.com/vytkuklys/42_cub3d/new/main?readme=1#contents)<br>

### Example
<img src="readme_additions/example.gif"/><br>

