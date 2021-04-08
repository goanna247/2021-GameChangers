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

  wayfinder::Path::lLine line1 {{{0,0}, {0.4,0}}};

  wayfinder::Path::lPath path1L {
    {
      line1
    }
  };
};