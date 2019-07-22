#ifndef __MERCANTILE_H_
#define __MERCANTILE_H_

namespace mercatortile{


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
    float lng;
    float lat;
};

// A x and y pair of web mercator
struct XY
{
    float x;
    float y;
};

// A geographic bounding box
struct LngLatBbox
{
    float west;
    float south;
    float east;
    float north;
};

// A web mercator bounding box
struct Bbox
{
    float left;
    float bottom;
    float right;
    float top;
};



void truncate_lonlat(float *lng, float *lat);

// Returns the upper left longitude and latitude of a tile
LngLat ul(const Tile &tile);

// Get the lonlat bounding box of a tile
LngLatBbox bounds(const Tile &tile);

// Convert longtitude and latitude to web mercator x, y.
XY xy(const float &lng, const float &lat);

// Convert  web mercator x, y to longtitude and latitude.
LngLat lonlat(const float &x, const float &y);

// Get the web mercator bounding box of a tile
Bbox xy_bounds(const Tile &tile);

// Get the tile containing a longitude and latitude
Tile tile(const float &lng, const float &lat, const int &zoom);



} //namespace mercatortile
#endif // !__MERCANTILE_H_