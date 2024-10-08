class Solution {
public:
    // Function to compute the total area covered by two rectangles
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        // Calculate the area of the first rectangle using the formula: height*width
        int area1 = (ay2 - ay1) * (ax2 - ax1);
        
        // Calculate the area of the second rectangle using the formula: height*width
        int area2 = (by2 - by1) * (bx2 - bx1);
        
        // Calculate the overlapped area of the two rectangles
        // The overlapping width is the distance between the right edge of the left rectangle
        // and the left edge of the right rectangle (or zero if they do not overlap)
        // The overlapping height is the distance between the top edge of the bottom rectangle
        // and the bottom edge of the top rectangle (or zero if they do not overlap)
        int overlaped_area = max(min(ax2, bx2) - max(ax1, bx1), 0) * max(min(ay2, by2) - max(ay1, by1), 0);
        
        // Return the total area covered by both rectangles, subtracting the overlapped area
        return area1 + area2 - overlaped_area;
    }
};
