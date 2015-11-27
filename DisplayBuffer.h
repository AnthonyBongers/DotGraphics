#pragma once

#include <iostream>
#include <vector>
#include "DataTypes.h"

/** DisplayBuffer
 *
 * The display buffer abstracts away the difficulties of braille graphics, so a
 * programmer can easily set, clear, and toggle dots as if they were a grid of
 * pixels.
 */
class DisplayBuffer
{
public:
  DisplayBuffer(DisplayRect viewport);
  
  // Draw method for setting bits on the display
  void set(DisplayPoint point, DrawMode mode);
  
  // Retrieves bit data at a given point from the display
  bool get(DisplayPoint point) const;
  
  // Completely clear the display
  void flush();
  
  // Output the display data to a stream (cout, file stream, etc)
  void print(std::ostream &stream);
  
  // Get the dimensions of the display
  DisplayRect getViewport() const;
  
private:
  std::vector<std::vector<unsigned char>> m_blocks;
  
  DisplayRect m_viewport;
  
  // Braille dot masks. Ordering of dots is:
  // 1 4
  // 2 5
  // 3 6
  // 7 8
  const int m_mask[4][2]
  {
    { 1  , 8   },
    { 2  , 16  },
    { 4  , 32  },
    { 64 , 128 },
  };
};