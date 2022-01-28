# cub3d

This guide is heavily abstracted from [This one](https://lodev.org/cgtutor/raycasting.html), If you cant understand the one provided, this guide is for you.

-  [Introduction](#introduction)
-  [Map parsing and validating](#map-parsing-and-validating)
-  [Player direction vector and camera vector](#player-direction-vector-and-camera-vector)
-  [DDA Algorithm](#dda-algorithm)
-  [Ray Casting implementation](#ray-properties)
-  [Camera plane vector](#camera-plane-vector)
-  [Image scaling and transformation for MLX](#image-scaling-and-transformation-for-MLX)
-  [Floor and ceiling colors](#floor-and-ceiling-colors)

Updated as of Jan 2022.

## Introduction
The new thing about this project is that we get to learn something called **raycasting**, which is a method of graphical programming to render 3D environments to a 2D screen. However, this method has its own pros and cons which includes:
- This method of rendering is lightweight and used by very old games where the machine has weak processing power
- This method is relatively easy to implement from scratch compared to its alternative [**raytracing**](https://en.wikipedia.org/wiki/Ray_tracing)

However, 
- This method assumes that all borders of the map are closed
- This method assumes that the map has constant height

The basic idea of raycasting is as follows: the map is a 2D square grid, and each square can either be 0 (= no wall), or 1 (= wall)

![Sample map](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/sample-map.png)

You then imagine your screen as a coordinate plane, and it seperated into columns (x - axis) like so :

![monitor](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/monitor.png)

For every x of the screen (i.e. for every vertical stripe of the screen), send out a ray that starts at the player location and with a direction that depends on both the player's looking direction, and the x-coordinate of the screen. Then, let this ray move forward on the 2D map, until it hits a map square that is a wall. If it hit a wall, calculate the distance of this hit point to the player, and use this distance to calculate how high this wall has to be drawn on the screen: the further away the wall, the smaller it's on screen, and the closer, the higher it appears to be. These are all 2D calculations.

The end result will look something like this :
![raycasting-animation](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/raycasting.gif)

... and thats pretty much the basic idea of raycasting. I will be talking about map parsing and validation next, so if you want to skip to the raycasting implementation, click [here](#player-direction-vector-and-camera-vector)

## Map parsing and validating
A valid map / config file obeys the following rules:
- The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation.
- The map must be closed/surrounded by walls
- Except for the map content, each type of element can be separated by one or more empty line(s).
- Except for the map content which always has to be the last, each type of element can be set in any order in the file.
- Except for the map, each type of information from an element can be separated
by one or more space(s).
- The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.

These are examples of valid map files.

![valid_map](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/valid_map.png)
![valid_map1](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/valid_map1.png)
![valid_map2](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/valid_map2.png)

I wont talk much about the texture and colors here. 
Unlike so_long, the rules of the map are laxed and allowing more creative freedom. The map will may not be rectangular in shape and may have many weird edges/curves and corners. However, the map can still be parsed as a 2d
character array and treated like normal strings with different lengths each row.

As such, I came up with a few map validation rules. Assume that we are scanning the map from top to bottom, left to right :

- Ignore all leading whitespaces.
- If the current row is the 0th row or the final row, only accept '1's and ' 's.
	-  else, The first and final character should always be a '1'.
- In the case of any non leading whitespaces, the only acceptable characters adjacent to the space are '1's or ' 's.
- If strlen(curr_row) > strlen(row_on_top) && current col > strlen(row_on_top), current character should be '1'
- If strlen(curr_row) > strlen(row_on_bottom) && current col > strlen(row_on_bottom), current character should be '1'

Those rules should pass all the map requirements given.

## Player direction vector and camera vector
Before we cast any rays, we will first have to determine WHERE to cast the rays. Obviously, we will have to define where the player is looking at.
We can do exacly that with a vector, like so.
![player_dir_vect](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/player_dir_vect.png)

In the image above, the player (green) is looking at the north direction straight up (red line). the direction can be defined as a vector with x and y components (y = +1, x = 0).
Now we know the vector that defines the players looking direction, we can use that vector to determine the camera vector (the vector that defines FOV). The camera vector is perpendicular to the players direction vector and can be defined as so. (purple line).

![cam_vect](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/cam_vect.png)

And we can connect the ends of both vectors, we will obtain a cone shaped viewing zone :
![cam_vect_2](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/cam_vect_2.png)

If the direction vector is much longer than the camera plane, the FOV will be much smaller than 90°, and you'll have a very narrow vision. You'll see everything more detailed though and there will be less depth, so this is the same as zooming in:

![cam_vect_3](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/cam_vect_3.png)

