
#include <TVout.h>
#include <fontALL.h>

/*
VIDEO OUTPUT
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 While VGA, DVI, and HDMI video are complex digital signals, the
 old-school analog video (sent over RCA connectors) is easy enough
 that your Arduino can generate it (with just a few caveats).
 
 Requires the TVout library - download and usage details:
 http://code.google.com/p/arduino-tvout
 
 Caveats (ie: disclaimers):
 1. Black and white only (no color or grayscale)
 2. Simple shapes, no images
 3. Can be a bit slow to refresh (16MHz is pretty slow for video processing)
 
 For full TVout capabilities, see the example 'DemoNTSC' included with
 the library.
 
 CHALLENGE:
 + Can you control the creation or size of shapes using different
   sensors? This is just a short step from Pong! (see the TVout Google
   Code page for Arduino-Tetris)
 + Look at the 'DemoNTSC' sketch in the TVout examples; in it graphics
   are defined as arrays. Can you write a sketch (using Processing,
   Python, Javascript, etc) that generates those arrays from an existing
   image file and returs an array? 
   
 */

int rectSize =     10;      // rectangle size
const int width =  128;     // width of screen (best when tuned to your display)
const int height = 96;      // listed as a 'const' since this doesn't change
TVout tv;                   // TVout object


void setup() {
  tv.begin(_NTSC, width, height);    // start TV connection
  tv.select_font(font8x8);           // create font for display
  
  // fill with random pixels
  for (int y=0; y<height; y++) {
    for (int x=0; x<width; x++) {
      if (random(10) > 5) {
        tv.set_pixel(x,y, WHITE);
      }
      else {
        tv.set_pixel(x,y, BLACK);
      }
    }
  }
  tv.delay(2000);
}


void loop() {

  // clear screen and draw shapes
  tv.clear_screen();
  tv.draw_rect(width/2-rectSize/2,height/2-rectSize/2, rectSize,rectSize, WHITE);
  tv.println(width/2-(5*8),height/2-8, "TELEVISION");    // offset 1/2 # of characters x 8px wide
  tv.println(width/2-8,height/2+8, ":(");                // emoticons for simple graphics*

  //  * parentheses seem reversed in the TVout lib... :(

  // update rectangle size; when too large, reset
  rectSize += 1;
  if (rectSize > width || rectSize > height) {
    rectSize = 10;
  }

  // OPTIONAL: wait before redrawing (may be helpful preventing your Arduino from freaking out)
  // try times that are even multiples of the 60Hz NTSC refresh rate
  tv.delay(60);
}


