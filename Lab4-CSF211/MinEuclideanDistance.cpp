#include<bits/stdc++.h>

// Point, a user-defined datatype to simplify syntax
struct Point {
    long long x, y;
};

// Comparison functions for sorting points by X or Y coordinates.
bool compareX(const Point &a, const Point &b) { return a.x < b.x; }
bool compareY(const Point &a, const Point &b) { return a.y < b.y; }

// Calculates squared Euclidean distance.
// We use squared distance (instead of sqrt) to maintain precision with integers.
long long distSq(const Point &p1, const Point &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// The recursive function. It returns the smallest squared distance found so far.
long long f(std::vector<Point> &points, int left, int right) {
    // Base Case: If we have a very small number of points (3 or fewer),
    // it's faster to just brute-force check every pair than to recurse further.
    if (right - left <= 3) {
        long long minD = LLONG_MAX;
        for (int i = left; i <= right; ++i) {
            for (int j = i + 1; j <= right; ++j) {
                minD = std::min(minD, distSq(points[i], points[j]));
            }
        }
        return minD;
    }

    // This divides the plane of points into two halves using a vertical line.
    int mid = (left + right) / 2;
    long long midX = points[mid].x;

    // Recursively find the smallest distance in the left half and right half.
    // 'd' becomes the "best" distance we've found completely within one side.
    long long d = std::min(f(points, left, mid), f(points, mid + 1, right));

    // Next, we combine the solutions to the two halves.
    // The minimum distance is either between a pair of points from the left half, a pair of points from the right half,
    // or a pair with one point on the left and one point on the right. 'd' is the minimum of the first two.
    // We need to calculate the third.

    // We create a "strip" of points that are close enough to the dividing line to matter.
    // If the squared horizontal distance is greater than 'd' (meaning the physical distance is > sqrt(d)) from the
    // middle line, it can't possibly form a pair closer than 'd' with a point on the other side.
    std::vector<Point> strip;
    for (int i = left; i <= right; ++i) {
        long long dx = points[i].x - midX;
        // Check if horizontal distance is less than our current minimum.
        if (dx * dx < d) {
            strip.push_back(points[i]);
        }
    }

    // Sort the strip by Y-coordinate. This allows us to scan efficiently from bottom to top.
    std::sort(strip.begin(), strip.end(), compareY);

    // Scan the strip for closer pairs.
    for (size_t i = 0; i < strip.size(); ++i) {
        // We only need to check the next few points.
        // Geometrically, because the points are sorted by Y and we are bound by 'd' on X,
        // we only need to check points within a small vertical window.
        for (size_t j = i + 1; j < strip.size(); ++j) {
            long long dy = strip[j].y - strip[i].y;

            // If the squared vertical distance alone is already greater than our current best 'd',
            // we stop checking this point against others. No point further up can be closer.
            // This prevents the nested loop from having n^2 complexity.
            if (dy * dy >= d) {
                break;
            }
            d = std::min(d, distSq(strip[i], strip[j]));
        }
    }
    return d;
}

long long solve(int n, std::vector<Point> &points) {
    // Pre-sort points by X coordinate so we can easily split them into left/right halves.
    std::sort(points.begin(), points.end(), compareX);
    return f(points, 0, n - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        std::vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }
        std::cout << solve(n, points) << std::endl;
    }
    return 0;
}