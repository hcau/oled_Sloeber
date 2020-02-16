// Do not remove the include below

#include "EcranLCD.h"

#include <HardwareSerial.h>
#include <string.h>
#include <WString.h>

/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).
 **************************************************************************/


char global_message[]="Hello my name's Herve Caujolle";
char global_message2[] = "coucou";
int global_x, global_minX, global_x2, global_maxX;
int global_count;

void setup() {
	//Initiate serial communication
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
//  display.display();
//  delay(2000); // Pause for 2 seconds

  // Clear the buffer
//  display.clearDisplay();

  // Draw a single pixel in white
//  display.drawPixel(10, 10, SSD1306_WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
//  display.display();
//  delay(2000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...

//  testdrawline();      // Draw many lines

//  testdrawrect();      // Draw rectangles (outlines)
//
//  testfillrect();      // Draw rectangles (filled)
//
//  testdrawcircle();    // Draw circles (outlines)
//
//  testfillcircle();    // Draw circles (filled)
//
//  testdrawroundrect(); // Draw rounded rectangles (outlines)
//
//  testfillroundrect(); // Draw rounded rectangles (filled)
//
//  testdrawtriangle();  // Draw triangles (outlines)
//
//  testfilltriangle();  // Draw triangles (filled)
//
//  testdrawchar();      // Draw characters of the default font
//
//  testdrawstyles();    // Draw 'stylized' characters
//
//  testscrolltext();    // Draw scrolling text
//
//  testdrawbitmap();    // Draw a small bitmap image
//
//  // Invert and restore display, pausing in-between
//  display.invertDisplay(true);
//  delay(1000);
//  display.invertDisplay(false);
//  delay(1000);
//
//  testanimate(logo_bmp, LOGO_WIDTH, LOGO_HEIGHT); // Animate bitmaps




	  display.setTextWrap(false);
	  global_x = display.width();
	  global_minX = -12*strlen(global_message); // 12 = (6 pixels par caractère)  X (taille du texte (ici 2))

	  global_maxX = display.width();
	  global_x2=0;
	  global_count = 0;

}

void loop() {
//	testdrawcircle();    // Draw circles (outlines)
//	testdrawchar();      // Draw characters of the default font

	global_count++;

	////////////////////////////////
	////Texte fixe.
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setCursor(0,7); // Set text position (X,Y)
	display.setTextSize(1); // Set text size to 1 (small)
	display.print("TEST SCROLLING TEXT"); // Print text


	////Défilement du texte.
	display.setTextSize(2); // Set text size to 1 (small)
	display.setCursor(global_x,20); // Set text position (X,Y)
	display.print(global_message);

	//Défilement de la droite vers la gauche.
	global_x-=4; //scroll speed
	if(global_x<global_minX){
		global_x = display.width();
	}

	//Ligne séparatrice
	display.drawLine(0,16,display.width()-1,16,WHITE);

	//Défilement de la gauche vers la droite.
	display.setTextSize(2); // Set text size to 1 (small)
	display.setCursor(global_x2,40); // Set text position (X,Y)
	display.print(global_message2);
	global_x2+=2; //scroll speed
	if(global_x2>global_maxX){
		global_x2 = 0;
	}


	display.display();


	//Débug
	Serial.print("maxX ="); Serial.print(global_maxX, DEC);
	Serial.println();
	Serial.print("x2 ="); Serial.print(global_x2, DEC);
	Serial.println();
//	Serial.flush();


//cf pour scroller : https://www.youtube.com/watch?v=sTYPuDMPva8

	if(global_count==250){
	testdrawcircle();
	testdrawrect();
	testfillcircle();
	testfilltriangle();
	testdrawbitmap();
	testfillroundrect();
	testscrolltext();
	testfillrect();      // Draw rectangles (filled)
	testdrawroundrect(); // Draw rounded rectangles (outlines)
	testdrawtriangle();  // Draw triangles (outlines)
	testdrawchar();      // Draw characters of the default font
	testdrawstyles();    // Draw 'stylized' characters


	global_count = 0;
	}

}



