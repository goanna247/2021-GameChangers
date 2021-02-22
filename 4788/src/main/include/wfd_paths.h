#pragma once

struct wfd_paths {
  /**
  * Create a spline using waypoints and control points
  */
  wayfinder::Path::sSpline spline1{
    {{1,0}, {2,0}}, // Waypoints

    {0,0}, // Start control point
    {5,0} // End Control point
  };

  /**
  * Path to use with follower
  */
  wayfinder::Path::sPath path;
};