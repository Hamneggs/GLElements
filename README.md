GLElements
====
----
This repository contains a bunch of 2D OpenGL elements that can be used to build a nice, swift, application.

Dependencies
====
----
This repository does use several existing libraries such as:
* GLEW - What better way is there to define functions like glUniformMatrix4fv()?
* FreeImage - This is used for texture loading. It's really robust for its size, and recommend it to anyone.
* GLM - I properly use matrices for location and camera data. This provides the mathematical functionality to do so.
* GLUT - It's there for misellaneous OpenGL functionality, but isn't entirely necessary for the use of the GL elements.
On the bright side, all of these libraries are included in src/dependencies. Just add these directories 
to your existing link and header directories and you are good to go!
