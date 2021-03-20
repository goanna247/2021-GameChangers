#pragma once

struct wfd_paths {
  /**
  * Create a spline using waypoints and control points
  */
  wayfinder::Path::sSpline spline1{
    {
      {0,0},
      {0,3}
                // {0,0}, 
                // {1,-1.5},
                // {2, -2},
                // {3, -2.5},
                // {4, -3},
                // {5, -3.5},
                // {6, -4},
                // {7, -4.5}
      // {0.8, 3},
      // {1.5, 2},
      // {0.8, 1},
      // {0.8, 0}

    }, // Waypoints

    {0,-1}, // Start control point
    {0,4}, // End Control point
    "poggers"
  };

  /**
  * Path to use with follower
  */
  wayfinder::Path::sPath path;
};