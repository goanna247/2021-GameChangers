#pragma once

struct wfd_paths {
  /**
  * Create a spline using waypoints and control points
  */
  wayfinder::Path::sSpline spline1{
    {
      {0,0},
      {4,1}
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

    {0,0}, // Start control point
    {4,2}, // End Control point
    "poggers"
  };

  /**
  * Path to use with follower
  */
  wayfinder::Path::sPath path;

  wayfinder::Path::lLine line1 {{{0,0}, {1,0}}};
  wayfinder::Path::lLine line2 {{{1,0}, {2,1}}};
  // wayfinder::Path::lLine line3 {{{2,0}, {3,0}}};
  // wayfinder::Path::lLine line4 {{{3,0}, {4,0}}};


  wayfinder::Path::lPath pathL {
    {
      line1,
      line2
      // line3,
      // line4
    }
  };
};