#include "DisplayBuffer.h"
#include <algorithm>

#define clamp(value, lo, hi) std::max(lo, std::min((int)value, hi));

DisplayBuffer::DisplayBuffer(DisplayRect viewport)
: m_viewport { viewport }
{
  // Round viewport up to nearest braille size
  int width  = (viewport.width  + 1) / 2;
  int height = (viewport.height + 3) / 4;
  
  m_blocks.resize(height);
  for (auto &v : m_blocks) v.resize(width);
}

DisplayRect DisplayBuffer::getViewport() const
{
  return m_viewport;
}

void DisplayBuffer::flush()
{
  for (auto &y : m_blocks) for (auto &x : y) x = 0;
}

void DisplayBuffer::set(DisplayPoint point, DrawMode mode)
{
  int x = clamp(point.x, 0, m_viewport.width);
  int y = clamp(point.y, 0, m_viewport.height);
  
  char mask = m_mask[y % 4][x % 2];
  
  if      (mode == DrawMode::Set)    m_blocks[y / 4][x / 2] |= mask;
  else if (mode == DrawMode::Clear)  m_blocks[y / 4][x / 2] &= ~mask;
  else if (mode == DrawMode::Toggle) m_blocks[y / 4][x / 2] ^= mask;
}

bool DisplayBuffer::get(DisplayPoint point) const
{
  int x = clamp(point.x, 0, m_viewport.width);
  int y = clamp(point.y, 0, m_viewport.height);
  
  return m_blocks[y / 4][x / 2] & m_mask[y % 4][x % 2];
}

void DisplayBuffer::print(std::ostream &stream)
{
  for (auto &y : m_blocks)
  {
    for (auto &x : y)
    {
      stream << (char[]) // Wishing there was a better way to generate unicode
      {
        '\xe2',
        (char)('\xa0' + x / 64),
        (char)('\x80' + x % 64),
        NULL
      };
    }
    
    stream << '\n';
  }
}