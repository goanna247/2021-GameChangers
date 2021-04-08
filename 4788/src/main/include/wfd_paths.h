#pragma once

struct wfd_paths {
  /**
  * Create a spline using waypoints and control points
  */
  wayfinder::Path::sSpline spline1{
    {
      {0,0},
      {1,0}
    }, // Waypoints

    {0,0},
    {1,0},
    "poggers"
  };

  /**
  * Path to use with follower
  */
  wayfinder::Path::sPath path;

  wayfinder::Path::lLine line1 {{{0,0}, {4,-1.5}}};
  wayfinder::Path::lLine line2 {{{4,-1.5}, {5,1}}};
  wayfinder::Path::lLine line3 {{{5, 1}, {6,-1}}};
  wayfinder::Path::lLine line4 {{{6,-1}, {7,0}}};



  wayfinder::Path::lPath path1L {
    {
      line1,
      line2,
      line3,
      line4
    }
  };
};