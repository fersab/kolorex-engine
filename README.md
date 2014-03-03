kolorex-engine
==============

Opengl 3.2+ 3D Rendering Engine

Works currently only on mac.

Lib deps:
  * Assimp
  * DevIl
  * glfw
  * Glut
  * OpenGL

Currenty shader support:
  * Faked ambiant light, white
  * Diffuse
  * Specular
  

General Todo:

  * Texture Mapping for all object loads
  * Deffered Rendering
  * Volumetric Scattering
  * Screen-Space-Ambient-Occlusion
  * HDR pipeline
  * Filmic tonemapping
  * Ambient Light approximation using a hemispherical ambient term (+ ssao contribution)
  * (Disc Shaped) Depth of Field
  * Punctual light sources using a microfacet BRDF (supports only directional light "yet")
  * Color Correction (artist definable using gradient texture)
  
