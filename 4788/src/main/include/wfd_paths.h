#pragma once

struct wfd_paths {
  /**
  * Create a spline using waypoints and control points
  */
  wayfinder::Path::sSpline spline1{
    {
      {0,0}, 
      {0,2},
      {1,3},
      {1,4}
    }, // Waypoints

    {0,-1}, // Start control point
    {1,5}, // End Control point
    "poggers"
  };

  /**
  * Path to use with follower
  */
  wayfinder::Path::sPath path;
};