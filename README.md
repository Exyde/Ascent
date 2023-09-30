# *Ascent*
 Ascent Engine - Creating a small engine in cpp with OpenGL.

# *Goals*
This project is for learning purposes only right now.
After the "Unity Crisis", I  was confused between leaving Unity and moving to Godot/Unreal, stay, or try something news.
I decided to not be "hard linked" to any kind of other proprietary engine for now, and dive back in to the core of the rendering. 
Parallel to this project I'll take a look at some others tools (Houdini/Substance to name a few)

# *Target* 
- 3D Scene View
- OBJ File Loading
- Shaders loading and editing support
- Basic interface with DearIMGUI
- Basic Transform System

# *Done*
- Basic Window Setup
- Standard Vertex and Fragment Shader Support.

# *Credits and Ressources*
I'm mainly following the documentation made by [Paroj](https://paroj.github.io/gltut/index.html) for now.

There's also some good references here :
- [Youtube Open GL Introduction Series](https://www.youtube.com/playlist?list=PLPaoO-vpZnumdcb4tZc4x5Q-v7CkrQ6M-)
- [IMGUI + GLFW Tutorial](https://www.youtube.com/watch?v=VRwhNKoxUtk)
- [Open Gl Text Tutorials](https://www.opengl-tutorial.org/)

________________________________

# Documentation and Side Notes

### Clip Space
*_Clip Space Transformation_*.  The first phase of rasterization is to transform the vertices of each triangle into a certain region of space. Everything within this volume will be rendered to the output image, and everything that falls outside of this region will not be. This region corresponds to the view of the world that the user wants to render.
The volume that the triangle is transformed into is called, in OpenGL parlance, clip space. The positions of the triangle's vertices in clip space are called clip coordinates.
Clip coordinates are a little different from regular positions. A position in 3D space has 3 coordinates. A position in clip space has four coordinates. The first three are the usual X, Y, Z positions; the fourth is called W. This last coordinate actually defines what the extents of clip space are for this vertex.

### [Rasterization Reminder](https://paroj.github.io/gltut/Basics/Intro%20Graphics%20and%20Rendering.html)
First step in putting the vertices of each triangle in Clip Space, outputting vertices in **Clip Coordinates**.
They are then transformed in **Normalized Devices Coordinates**. Each Vertex positions in Clip Space is divided by W. All coordonates are now in range [-1, 1]
Then it's converted in **Window Coordinates**. They are float coordinates in window space. [0,0] is the origin, at bottom left. Z is in range [0, 1], with 0 the closest and 1 the further. The rest is discarded.
Triangle then goes through **Scan Conversion**. This step produce a **fragment** for every pixel sample present in the triangle area. This process mainly happend in 2D, using X and Y Coordinates. Z is kept in the fragment, giving us it's **depth**. Also this process will give the same outputs for the same vertex (*invariance guarantee*).
Then the end : **Fragment processing**, transforming the fragment in one or more color values + 1 depth value. All the fragments of a triangle are processed until the next. Then is **Fragment Writing**, the fragment is written to the **destination image**. (combinating colors, depth, etc... Get back later !)
Some of this step can be hooked in by **Shaders** (Vertex, Fragment... and more) to add complexity, offset so CPU Load and much more !

# Questions / Explorations
- How to use different Context/Windows ?