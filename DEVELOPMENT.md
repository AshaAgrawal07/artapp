**log 4/21**    

Just realized that I needed a development.md file, so I'll put the entire week's worth of notes down here

1. color_ramp vs built in slider function  
  I originally imported an ofxColorGradient addon to get colors for the pen, but might replace it with the built-in color slider from the ofxGUI since it also has an alpha component so the user can affect the saturation/brightness of the color.  Although this means that the user can manually affect the rgba using 4 different sliders, the user might not be able to see the sample of the color beforehand.  This means that the user will have to test stroke the color, undo the stroke, and go through an entire process of trial and error before finding the color they really want.  Although this will not negatively effect their artwork, it will be tedius and annoying.

2. changing renderers  
  I am using an addon called ofxShivaVG which will help create better and smoother strokes/shapes that are not as pixelated.  A problem I faced was when I tried to use it was that I was not able to use its functions properly.  I had followed the instruction found on their readme, which still was not working.  When I went to the example code that they had, I realized that I had to change the renderer and use ofAppsGlutWindows, which I put into my main.
 
3. enums vs classes  
  I had initally created enums for pens/erasers/shapes, but will be creating classes for them instead as per the feedback during code review today.

**log 4/24**  
1. Figuring out functions for classes  
  This seems trivial, but in terms of thinking about expanding the project and the functionalities of the tools (each have a class), figuring out which functions each class should have is pretty important.  At first, I created a 'drawer', which is the basic drawing tool.  It has two children so far: pen and eraser.  Technically, eraser will have all of the same functionalities as pen, though its rgb can only be set once (to the initial background color) and its alpha value can change with its upper bound (? <-- need to check if its UB or LB) as the alpha value of the background color. That means that I will have to write overrides for the set rgba to take into account the restrictions on the eraser 

**log 4/25**
1. Inheritance is confusing  
  Trying to figure out how inheritance works in C++ using sites:  
  https://stackoverflow.com/questions/357307/how-to-call-a-parent-class-function-from-derived-class-function  
  https://stackoverflow.com/questions/6187020/access-base-class-variable-from-child-class-method  
  https://www.geeksforgeeks.org/inheritance-in-c/  
  
**log 4/27**
1. Inheritance was still not working  
  Person at office hours told me to add 'virtual' keyword infront of functions in the parent class to allow polymorphism.  
  
2. ofxShivaVG  
  For some reason, there is a file in in the addon which does not let my code compile.  I deleted it and the code started compiling.
  
**log 4/28**  
1. ofRunApp(new ofApp())  
  For some reason, ofApp() is not being recognized and message is saying that the function was deleted.  I have no clue when I deleted it or if I even did.  Turns out that I had to create a default constructor for Tool; it compiles now.

**log 4/30**  
1. Gui stuff not showing up  
  I've been trying to get the sliders and toggle button to show up for some time, but it is not.  I have my setBackGround() after the slider initializations, and I have tried setting BG to different colors manually, which works.  So I don't get why the sliders don't show up. Went to office hours and realized that I needed to call draw() on all of my gui stuff.

2. AddListeners  
  I think I need to add AddListeners to my toggle button so that I can use them in the update function (which I still need to write).   

3. Slider not working properly  
  The pen for some reason only draws with white, though the default is a grayish color, and I am not able to slide or toggle anything.  I think I might have to create a canvas such that the pen only works when its on the canvas's coordinates, and works as a noraml clicker by the sliders and toggle button.  
  UPDATE:  rgb and thickness is changing; thickness changing directly effects the pen width, but rgb changing isn't changing the actual color that the pen is drawing.  Also, the previous stroke disappears once I start drawing the next.
  
**log 5/1**  
1. Problems I need to solve to finish:  
    a) Get alpha slider to move (it's currently stuck on 255)  
    b) Get the color of the slider to reflect in the color of the stroke  
    c) Make sure that the strokes stay in the stack of strokes rather than disappearing  
    d) Make sure toggle button is working correctly  
I have been using http://pdf.th7.cn/down/files/1603/openFrameworks%20Essentials.pdf (openFrameworks Essentials) and its example programs to figure out how to fix some of my problems, but its not working.    
  UPDATE: color now shows up on the stroke (needed to use ofSetColor(colorslider) rather than using Tool's setColor function) 
  
2. Redrawing strokes  
  I realized that I need to redraw everything on the stack of strokes in the draw function so that the strokes don't disappear.  So using a stack won't be the greatest thing, or even a vector of ofPoints because it doesn't have a draw function.  I'm going to change strokes to a vector of ofPolyLines, which does have a draw function.  
  UPDATE: separate strokes are now showing up, I needed to use mouse inputs as well or else everything would count as a single stroke regardless of whether or not the mouse is pressed.  I used this link: http://openframeworks.cc/ofBook/chapters/intro_to_graphics.html to get the separate strokes to work.  This also means that I no longer use some of the logic I took from the ofxVectorGraphicsExample.  
  WHAT I NEED TO DO NEXT: although the strokes are separate, when I change color or thickness after I draw the strokes, all of them change to whatever the gui is indicating (ex. if I drew a blue swirly, and then changed the color to purple, the swirly will turn purple even if I don't want it to be purple.)  
  
3. Alpha slider  
  The reason why my alpha slider wasn't working was because when I setup my colorslider, my min color is black (alpha = 255), and max color was white (alpha = 255); so my alpha could only ever be 255.  I changed the min value in my setup using ofColor::fromHex(0, 0), which is black with an alpha value of 0.  
  
4. Stuff left  
  a) get the toggle buttons to work properly (or I will just delete the entire eraser function from my proposal)  
  b) make each stroke independent in its color and thickness (need to do b before a)  

5. Final changes  
  I realized that making each stroke independent in its color and thickness will mean that I will have to change how each stroke is made/stored, which may take longer than the given deadline.  So I changed my project proposal, making the stroke independencies and eraser function as things to be done to expand the project later on.  I added two functionalities in their places: saving the gui settings and the drawing itself.
