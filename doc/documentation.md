# *Documentation and Side Notes*

[Back to the the readme](../README.md)

______________

### *Clip Space / Clip Space Transformation*
The first phase of rasterization is to transform the vertices of each triangle into a certain region of space. Everything within this volume will be rendered to the output image, and everything that falls outside of this region will not be. This region corresponds to the view of the world that the user wants to render.
The volume that the triangle is transformed into is called, in OpenGL parlance, clip space. The positions of the triangle's vertices in clip space are called clip coordinates.
Clip coordinates are a little different from regular positions. A position in 3D space has 3 coordinates. A position in clip space has four coordinates. The first three are the usual X, Y, Z positions; the fourth is called W. This last coordinate actually defines what the extents of clip space are for this vertex.

### [Rasterization Reminder](https://paroj.github.io/gltut/Basics/Intro%20Graphics%20and%20Rendering.html)
First step in putting the vertices of each triangle in Clip Space, outputting vertices in **Clip Coordinates**.
They are then transformed in **Normalized Devices Coordinates**. 
Each Vertex positions in Clip Space is divided by W. All coordonates are now in range [-1, 1]
Then it's converted in **Window Coordinates**.
They are float coordinates in window space. [0,0] is the origin, at bottom left. Z is in range [0, 1], with 0 the closest and 1 the further. The rest is discarded.

Triangle then goes through **Scan Conversion**. This step produce a **fragment** for every pixel sample present in the triangle area. This process mainly happend in 2D, using X and Y Coordinates. Z is kept in the fragment, giving us it's **depth**. Also this process will give the same outputs for the same vertex (*invariance guarantee*).

Then the end : **Fragment processing**, transforming the fragment in one or more color values + 1 depth value. All the fragments of a triangle are processed until the next. Then is **Fragment Writing**, the fragment is written to the **destination image**. (combinating colors, depth, etc... Get back later !)
Some of this step can be hooked in by **Shaders** (Vertex, Fragment... and more) to add complexity, offset so CPU Load and much more !


____

### Projections
A projection, in term of *rendering pipeline* is a way to transform a world *from one dimensionality to another*.
*Finite Projecton* transform the world from one dimension *to a lower* one. (Our case).

**Orthographic Projection** : Flatenned, throw away the coordinate perpendicular to the surface. It capture the cube in front of it.

**Perspective Projection** : Realistical - The world is seen from and though a single point. It capture a larger part of the world.
In 2D the shape is a *regular trapezoid*.  In 3D the shape is called a **Frustrum** (kinda a pyramid with the tip chopped away !). 

#### Mathematical Perspective
Base assumptions for ou start work here 
- The plane projection is *axis-aligned*, face down the **-Z** awis (-Z is behind us, far away).
- The eye point is fixed at **[0, 0, 0]**
- The plane size is *[-1, 1]*. Everything outside this range is not drawn. Remember, we're projecting 3D thing on a 2D Plane !

Well, it sounds like **Normalized Device Coordinates...** But hold on.

The things are :
- Vertices further in Z axis are pushed away from the eye.
- Vertices further in XY axis, aka away from center, are pushed away as well (Because of the shape of the frustrum)

{TODO} -> [Re-read](file:///home/sly/workspace/dive/gltut/website/Positioning/Tut04%20Perspective%20Projection.html)

_____

## *Questions / Explorations*
- How to use different Context/Windows ?
- How to set differents Shaders Options ? Can we pass multiple vertex shader ? ( not sure )
______________
[Back to the the readme](../README.md)
______________