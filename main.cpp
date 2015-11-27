#include <iostream>
#include "Turtle.h"

int main()
{
  // Create the buffer to draw on
  DisplayBuffer buffer({ 240, 240 });
  
  // Get the center of the display
  DisplayPoint origin
  {
    (double)buffer.getViewport().width / 2,
    (double)buffer.getViewport().height / 2
  };
  
  double offset = 0.0;
  
  for (;;)
  {
    // Create a turtle in the middle of the screen, and spin it over time
    Turtle turtle(&buffer, origin);
    turtle.right(offset);
    
    // Create 36 circles, each spun 10 degrees apart
    for (int i = 0; i < 36; ++i)
    {
      turtle.right(10);
      
      for (int r = 0; r < 36; ++r)
      {
        turtle.right(10);
        turtle.forward(10);
      }
    }
    
    // Print the buffer to the terminal and then clear it for the next frame
    buffer.print(std::cout);
    buffer.flush();
    
    // Escape-code for clearing the screen in the terminal
    std::cout << "\e[1;1H" << std::flush;
    
    offset += 0.2;
  }
}
