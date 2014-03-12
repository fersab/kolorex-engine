kolorex-engine
==============

The Kolorex Engine - Opengl 3.2+ 3D Rendering Engine

Works currently only on mac.

Lib deps:
  * Assimp
  * DevIl
  * glfw
  * Glut
  * OpenGL


Current shaders:
  * Faked ambient light, white
  * Diffuse
  * Specular
  

General TODO:

  * Texture Mapping for all object loads (done, tested on obj and 3ds, no multitexture support until needed)
  * Deffered Rendering
  * Volumetric Scattering
  * Integrate BULLET for physics
  * Particle Engine
  * Normal Mapping
  * Parallax Mapping
  * Screen Space Ambient Occlusion (SSAO)
  * Full Scene Anti Aliasing (FSAA)
  * HDR pipeline
  * Filmic tonemapping
  * (Disc Shaped) Depth of Field
  * Light sources using a microfacet BRDF, use Cook-Torrance for Geometry and Blinn Phong for Distrubution 
  * Color Correction (artist definable using gradient texture)
  * Enviromental Mapping 
  * Shadow Mapping, dynamic shadows
  * Liquid-engine, voxel driven using marching cubes + physics
  * FPS counter
  * Scene Graph, node based or something
  * Destruction
  * Animations
  
