#pragma once

// A point on the display buffer.
// Instead of using integers, we use doubles since rounding errors can
// accumulate over time otherwise.
struct DisplayPoint
{
  DisplayPoint() {}
  DisplayPoint(double x, double y)
  : x { x }, y { y } {}
  
  double x {};
  double y {};
};

// Defines a height and width for use on the display buffer.
// Used for setting up the viewport, defining areas, drawing squares, etc.
struct DisplayRect
{
  DisplayRect() {}
  DisplayRect(int w, int h)
  : width { w }, height { h } {}
  
  int width {};
  int height {};
};

// The method of drawing a point onto the display buffer.
// Set will always set a display point on.
// Clear will always set a display point off.
// Toggle will toggle a display point to the opposite of it's current value.
enum class DrawMode
{
  Set,
  Clear,
  Toggle
};