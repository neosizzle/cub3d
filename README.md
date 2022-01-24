# cub3d

This guide is heavily abstracted from [This one](https://lodev.org/cgtutor/raycasting.html), If you cant understand the one provided, this guide is for you.

-  [Introduction](#inrtoduction)
-  [Map parsing and validating](#map-parsing-and-validating)
-  [Player direction vector and camera vector](#player-direction-vector-and-camera-vector)
-  [Ray Properties](#ray-properties)
-  [DDA Algorithm](#dda-algorithm)
-  [Camera plane vector](#camera-plane-vector)
-  [Image scaling and transformation for MLX](#image-scaling-and-transformation-for-MLX)
-  [Floor and ceiling colors](#floor-and-ceiling-colors)
-  [Player rotation and movement](#player-rotation-and-movement)

Updated as of Jan 2022.

## Introduction
The new thing about this project is that we get to learn something called **raycasting**, which is a method of graphical programming to render 3D environments to a 2D screen. However, this method has its own pros and cons which includes:
- This method of rendering is lightweight and used by very old games where the machine has weak processing power
- This method is relatively easy to implement from scratch compared to its alternative [**raytracing**](https://en.wikipedia.org/wiki/Ray_tracing)

However, 
- This method assumes that all borders of the map are closed
- This method assumes that the map has constant height

The basic idea of raycasting is as follows: the map is a 2D square grid, and each square can either be 0 (= no wall), or 1 (= wall)
![Sample map](https://github.com/neosizzle/cub3d/blob/main/pictures/sample-map.png)
