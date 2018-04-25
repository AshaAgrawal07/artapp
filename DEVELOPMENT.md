**log 4/21**  

Just realized that I needed a development.md file, so I'll put the entire week's worth of notes down here
---
1. color_ramp vs built in slider function
  I originally imported an ofxColorGradient addon to get colors for the pen, but might replace it with the built-in color slider from the ofxGUI since it also has an alpha component so the user can affect the saturation/brightness of the color.  Although this means that the user can manually affect the rgba using 4 different sliders, the user might not be able to see the sample of the color beforehand.  This means that the user will have to test stroke the color, undo the stroke, and go through an entire process of trial and error before finding the color they really want.  Although this will not negatively effect their artwork, it will be tedius and annoying.

2. changing renderers
  I am using an addon called ofxShivaVG which will help create better and smoother strokes/shapes that are not as pixelated.  A problem I faced was when I tried to use it was that I was not able to use its functions properly.  I had followed the instruction found on their readme, which still was not working.  When I went to the example code that they had, I realized that I had to change the renderer and use ofAppsGlutWindows, which I put into my main.
 
3. enums vs classes
  I had initally created enums for pens/erasers/shapes, but will be creating classes for them instead as per the feedback during code review today.

**log 4/24**  
1. Figuring out functions for classes
  This seems trivial, but in terms of thinking about expanding the project and the functionalities of the tools (each have a class), figuring out which functions each class should have is pretty important.  At first, I created a 'drawer', which is the basic drawing tool.  It has two children so far: pen and eraser.  Technically, eraser will have all of the same functionalities as pen, though its rgb can only be set once (to the initial background color) and its alpha value can change with its upper bound (? <-- need to check if its UB or LB) as the alpha value of the background color. That means that I will have to write overrides for the set rgba to take into account the restrictions on the eraser 
