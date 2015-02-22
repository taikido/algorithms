/*
    Rectangle can be defined by its upper left and lower right corners
    Assume:
        l1 and r1 are the upper left and lower right corners of Rect 1
        l2 and r2 are the upper left and lower right corners of Rect 2
    Instead of enumerating all the cases where a point could be in a rectangle,
    check the opposite conditions:

    2 Rectangles do not overlap if one is to the left or right of the other
    or 1 is above/below the other

    Sources:
        http://www.geeksforgeeks.org/find-two-rectangles-overlap/
        http://leetcode.com/2011/05/determine-if-two-rectangles-overlap.html

*/

struct Point
{
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
};

bool doOverlap(Point& l1, Point& r1, Point& l2, Point& r2))
{
    // Check if one rect is above the other
    if (r2.y > l1.y || r1.y > l2.y) return false;

    // IF is one rect is to the left of the other
    if (r2.x < l1.x || r1.x < l2.x) return false;

    return true;
}