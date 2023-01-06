# CSC4900-Graphics-Engine
Seattle Pacific University Independent Study Course Project - Graphics Engine Building

# Independent Study Learning Plan
Noah Gallo – Winter 2023

Textbook:  Learn OpenGL by Joey de Vries 
- Free online version can be found at: https://learnopengl.com/ 

## Development Schedule

### Jan 9 – 23: Basic Setup
- Textbook chapter 1: Getting Started 
- Get OpenGL Up and running 
- Design a structure for storing Objects 
	- Meshes
	- Shaders
	- Textures
-	Allow Mesh Import and Export
	-	May use 3rd party library
-	Create a scene Structure
	-	Allow saving and loading scenes
- Create a free roam camera

### Jan 23 – Feb 6: Lighting and Shaders
-	Textbook Chapter 2: Lighting
-	Textbook Chapter 3: Model Loading
-	Textbook Chapter 4: Advanced OpenGL (Partial)
-	Design a shader using a simple lighting algorithm
	-	Example: Diffuse Lighting
-	Create a light source object

### Feb 6 – 20: Advanced OpenGL, Editor and Text/UI Rendering 
-	Textbook Chapter 4: Advanced OpenGL
-	Text and UI may be more advanced than expected. May have to push this back
-	Textbook Chapter 7: In Practice
-	Implement Text Rendering
-	Work on a simple UI system
	-	Buttons
	-	Input Fields
		-	Text
		- Slider
		- Etc.
-	Implement a way to edit scenes from the application itself (This could use some other application software and doesn't have to be built directly in OpenGL)
	-	Add, Move, Rotate and Scale objects

### Feb 20 – March 6:  Finished Graphics Engine 
-	This is a chance to tie any loosed ends together on the final project for the course. 
-	The entire graphics engine and documentation ought to be finished by this time

### March 6 – 16: This is a buffer time for making sure to complete all the previous steps. If the Final Project and website are complete by this time, pick one of the items below to research/implement
-	Choose any of the following to work on 
	-	Advanced OpenGL 
		-	Blending, Advanced Shaders, Framebuffers…
	-	Mesh based Animations
	-	Sprite Based Animation
	- Physics Engine
		-	Using the Graphics engine created previously, design a way for different objects to interact physically
			-	Must have Simple Mesh Collisions 
				-	Cubes, Spheres, Capsules
			- Could have complex mesh collisions
				- Create colliders based on an objects mesh
	-	Physically Based Rendering (PBR) - Must Complete Advanced OpenGL first
		-	Following the textbook chapter, implement some forms of PBR rendering for your objects
	-	Advanced Graphics:
		-	Ray-Tracing
	-	Follow the lectures on light transport and create a report (no coding)
	-	Mesh Editor:
		-	A simple cube based mesh editor
	-	Marching Cubes
		-	An algorithm for sculpting meshes
	-	Compute Shaders - Concurrent Computing using the GPU and GLSL
	-	Create an application with the Rendering Engine
 
## Deliverable Due Dates
### January 23rd
-	Deliverable: 
	-	An unlit demo scene containing at least 1 object 
	-	A camera controller for navigating the scene (basic free roam camera)
		-	Do not worry about gimble lock(something to do with quaternions, not exactly sure how it works)
	-	Website: Write a tutorial for the initial setup of OpenGL, including a bare bones vertex and fragment shader
### February 6th
-	Deliverable: 
	-	A lit demo scene containing at least 2 Objects (with distinct meshes) and 1 light source (colored)
-	Website: 
	-	Create a page describing the chosen lighting algorithm and how to implement it
	-	Create a page on shaders, how they work, and how they are implemented
### February 20th
-	Deliverables: 
	-	A Demo Scene containing at least 5 different meshes, 3 light sources (preferably of different color and/or type), and contains some form of movement. 
***If Possible:***
-	Create a start menu that:
	-	allows you to select from one of the previous demo scenes
	-	Contains some form of input field (perhaps something like brightness level)
-	A scene editor that allows you to add, move, rotate, and scale 3D object in the scene
- Website: 
	-	Document the different objects you have
		-	Light source
		-	Mesh
		-	Texture
		-	Material
		-	Etc. 
###	March 6th – **Final Graphics engine is due with full documentation on the website**

If the graphics engine is completed and satisfactory before the end of the quarter, I will put time into researching one of the topics written above. Likely, I will not turn anything in on this topic, unless I end with a lot of extra time. 
