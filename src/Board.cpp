#include "Board.h"

Board::Board()
    : _home_width(4)
    , _radius(4)
    , _background('.')
{
    // Players 1-6, numbered from top counterclockwise
    SetTopStart('1');
    SetUpperLeftStart('2');
    SetLowerLeftStart('3');
    SetBottomStart('4');
    SetLowerRightStart('5');
    SetUpperRightStart('6');

    // board center
    SetCenter('*');
}

void Board::SetTopStart(char c)
{
    // start at radius from center and move down, decreasing width of layer at each step
    int width = _home_width;
    for (int z = -(_radius+1); z >= -(2*_radius); --z) {
        for (int x = _home_width - width + 1; x <= _home_width; ++x) {
            CubePoint cube {x, -x-z, z};
            _state[cube] = c;
        }
        --width;
    }
}

void Board::SetUpperLeftStart(char c)
{
    // start at radius from center and move out, decreasing width of layer at each step
    int width = _home_width;
    for (int y = _radius+1; y <= 2*_radius; ++y) {
        for (int x = -_home_width; x <= -_home_width + width -1; ++x) {
            CubePoint cube {x, y, -x-y};
            _state[cube] = c;
        }
        --width;
    }
}

void Board::SetLowerLeftStart(char c)
{
    // start at radius from center and move out, decreasing width of layer at each step
    int width = _home_width;
    for (int x = -(_radius+1); x >= -(2*_radius); --x) {
        for (int y = _home_width - width + 1; y <= _home_width; ++y) {
            CubePoint cube {x, y, -x-y};
            _state[cube] = c;
        }
        --width;
    }
}

void Board::SetBottomStart(char c)
{
    // start at radius from center and move out, decreasing width of layer at each step
    int width = _home_width;
    for (int z = _radius+1; z <= 2*_radius; ++z) {
        for (int x = -_home_width; x <= -_home_width + width -1; ++x) {
            CubePoint cube {x, -x-z, z};
            _state[cube] = c;
        }
        --width;
    }
}

void Board::SetLowerRightStart(char c)
{
    // start at radius from center and move out, decreasing width of layer at each step
    int width = _home_width;
    for (int y = -(_radius+1); y >= -(2*_radius); --y) {
        for (int x = _home_width - width + 1; x <= _home_width; ++x) {
            CubePoint cube {x, y, -x-y};
            _state[cube] = c;
        }
        --width;
    }
}

void Board::SetUpperRightStart(char c)
{
    // start at radius from center and move out, decreasing width of layer at each step
    int width = _home_width;
    for (int x = _radius+1; x <= 2*_radius; ++x) {
        for (int y = -_home_width; y <= -_home_width + width -1; ++y) {
            CubePoint cube {x, y, -x-y};
            _state[cube] = c;
        }
        --width;
    }
}

void Board::SetCenter(char c)
{
    CubePoint center {0, 0, 0};
    // fill in all cells within radius from center, converting from cube to hex
    for (int x = -_radius; x <= _radius; ++x) {
        for (int y = std::max(-_radius, -x-_radius); y <= std::min(_radius, -x+_radius); ++y) {
            int z = -x-y;
            CubePoint cube {x, y, z};
            _state[cube] = c;
        }
    }
}

void Board::Display(std::ostream& os) const
{
    // print q axis
    os << "   ";
    for (int q = -_radius -_home_width; q <= _radius + _home_width; ++q) {
        os << (q < 0 ? -q : q) << " ";
    }
    os << std::endl;
    int r = -8;
    for (int row = 0; row <= 2*_radius + 2*_home_width; ++row) {
        if (r>=0) {
            os << " ";
        }
        // print r labels
        os << r << " ";

        int q = -8;
        // print filled cells or background
        for (int col = 0; col <= 2*_radius + 2*_home_width; ++col) {
            auto cell = _state.find({q,r});
            if (cell != _state.end()) {
                os << cell->second << " ";
            }
            else {
                os << _background << " ";
            }
            ++q;
        }
        os << std::endl;
        ++r;
    }
}
