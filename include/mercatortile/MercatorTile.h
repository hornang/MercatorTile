#ifndef __MERCANTILE_H_
#define __MERCANTILE_H_

#include <deque>
#include <string>
#include <vector>

#include "mercatortile_export.h"

namespace mercatortile
{

// An XYZ web mercator tile
struct Tile
{
    int x;
    int y;
    int z;
};

// A longitude and latitude pair
struct LngLat
{
    double lng;
    double lat;
};

// A x and y pair of web mercator
struct XY
{
    double x;
    double y;
};

// A geographic bounding box
struct LngLatBbox
{
    double west;
    double south;
    double east;
    double north;
};

// A web mercator bounding box
struct Bbox
{
    double left;
    double bottom;
    double right;
    double top;
};

MERCATORTILE_EXPORT void truncate_lonlat(double *lng, double *lat);

// Returns the upper left longitude and latitude of a tile
MERCATORTILE_EXPORT LngLat ul(const Tile &tile);

// Get the lonlat bounding box of a tile
MERCATORTILE_EXPORT LngLatBbox bounds(const Tile &tile);

// Convert longtitude and latitude to web mercator x, y.
MERCATORTILE_EXPORT XY xy(const double &lng, const double &lat);

// Convert  web mercator x, y to longtitude and latitude.
MERCATORTILE_EXPORT LngLat lnglat(const double &x, const double &y);

// Get the web mercator bounding box of a tile
MERCATORTILE_EXPORT Bbox xy_bounds(const Tile &tile);

// Get the tile containing a longitude and latitude
MERCATORTILE_EXPORT Tile tile(const double &lng, const double &lat, const int &zoom);

// Get the parent of a tile
MERCATORTILE_EXPORT Tile parent(const Tile &tile);
MERCATORTILE_EXPORT Tile parent(const Tile &tile, const int &zoom);

// Get the child of a tile
MERCATORTILE_EXPORT std::vector<Tile> children(const Tile &tile);
MERCATORTILE_EXPORT std::vector<Tile> children(const Tile &tile, const int &zoom);

// Get the tiles intersecting a geographic bounding box
MERCATORTILE_EXPORT std::vector<Tile> tiles(const LngLatBbox &bbox, const int &zoom);

// Get the quadkey of a tile
MERCATORTILE_EXPORT std::string quadkey(const Tile &tile);

// Get the tile corresponding to a quadkey
MERCATORTILE_EXPORT Tile quadkey_to_tile(const std::string &qk);

} // namespace mercatortile

#endif // !__MERCANTILE_H_
